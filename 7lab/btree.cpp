#include <iostream>
using namespace std;

class BTreeNode {
public:
    int *keys;      // массив ключей
    int t;          // минимальная степень (порядок)
    BTreeNode **children; // массив указателей на дочерние узлы
    int n;          // текущее количество ключей
    bool leaf;      // true если узел является листом

    BTreeNode(int _t, bool _leaf) {
        t = _t;
        leaf = _leaf;
        keys = new int[2 * t - 1];
        children = new BTreeNode *[2 * t];
        n = 0;
    }

    ~BTreeNode() {
        delete[] keys;
        delete[] children;
    }

    void traverse() {
        for (int i = 0; i < n; i++) {
            if (!leaf) {
                children[i]->traverse();
            }
            cout << keys[i] << " ";
        }
        if (!leaf) {
            children[n]->traverse();
        }
    }


    BTreeNode* search(int k) {
        int i = 0;
        while (i < n && k > keys[i]) {
            i++;
        }
        if (i < n && keys[i] == k) {
            return this;
        }
        if (leaf) {
            return nullptr;
        }
        return children[i]->search(k);
    }

    void insertNonFull(int k) {
        int i = n - 1;

        if (leaf) {
            while (i >= 0 && keys[i] > k) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
            n++;
        } else {
            while (i >= 0 && keys[i] > k) {
                i--;
            }
            if (children[i + 1]->n == 2 * t - 1) {
                splitChild(i + 1);
                if (keys[i + 1] < k) {
                    i++;
                }
            }
            children[i + 1]->insertNonFull(k);
        }
    }

    void splitChild(int i) {
        BTreeNode *z = new BTreeNode(t, children[i]->leaf);
        BTreeNode *y = children[i];
        z->n = t - 1;

        for (int j = 0; j < t - 1; j++) {
            z->keys[j] = y->keys[j + t];
        }

        if (!y->leaf) {
            for (int j = 0; j < t; j++) {
                z->children[j] = y->children[j + t];
            }
        }

        y->n = t - 1;

        for (int j = n; j >= i + 1; j--) {
            children[j + 1] = children[j];
        }
        children[i + 1] = z;

        for (int j = n - 1; j >= i; j--) {
            keys[j + 1] = keys[j];
        }
        keys[i] = y->keys[t - 1];
        n++;
    }

    void remove(int k) {
        int idx = findKey(k);

        if (idx < n && keys[idx] == k) {
            if (leaf) {
                removeFromLeaf(idx);
            } else {
                removeFromNonLeaf(idx);
            }
        } else {
            if (leaf) {
                cout << "The key " << k << " is not found in the tree." << endl;
                return;
            }

            bool isLastChild = (idx == n);
            if (children[idx]->n < t) {
                fill(idx);
            }

            if (isLastChild && idx > n) {
                children[idx - 1]->remove(k);
            } else {
                children[idx]->remove(k);
            }
        }
    }

private:
    int findKey(int k) const {
       int idx=0;
       while(idx<n && keys[idx]<k)
           ++idx;
       return idx;
   }

   void removeFromLeaf(int idx) {
       for (int i = idx + 1; i < n; i++) {
           keys[i - 1] = keys[i];
       }
       n--;
   }

   void removeFromNonLeaf(int idx) {
       int k = keys[idx];

       if (children[idx]->n >= t) {
           int pred = getPredecessor(idx);
           keys[idx] = pred;
           children[idx]->remove(pred);
       } else if (children[idx + 1]->n >= t) {
           int succ = getSuccessor(idx);
           keys[idx] = succ;
           children[idx + 1]->remove(succ);
       } else {
           merge(idx);
           children[idx]->remove(k);
       }
   }

   int getPredecessor(int idx) {
       BTreeNode *current = children[idx];
       while (!current->leaf) {
           current = current->children[current->n];
       }
       return current->keys[current->n - 1];
   }

   int getSuccessor(int idx) {
       BTreeNode *current = children[idx + 1];
       while (!current->leaf) {
           current = current->children[0];
       }
       return current->keys[0];
   }

   void fill(int idx) {
       if (idx != 0 && children[idx - 1]->n >= t) {
           borrowFromPrev(idx);
       } else if (idx != n && children[idx + 1]->n >= t) {
           borrowFromNext(idx);
       } else {
           if (idx != n) {
               merge(idx);
           } else {
               merge(idx - 1);
           }
       }
   }

   void borrowFromPrev(int idx) {
       BTreeNode *child = children[idx];
       BTreeNode *sibling = children[idx - 1];

       for (int i = child->n - 1; i >= 0; i--) {
           child->keys[i + 1] = child->keys[i];
       }

       if (!child->leaf) {
           for (int i = child->n; i >= 0; i--) {
               child->children[i + 1] = child->children[i];
           }
       }

       child->keys[0] = keys[idx - 1];

       if (!child->leaf) {
           child->children[0] = sibling->children[sibling->n];
       }

       keys[idx - 1] = sibling->keys[sibling->n - 1];

       child->n += 1;
       sibling->n -= 1;
   }

   void borrowFromNext(int idx) {
       BTreeNode *child = children[idx];
       BTreeNode *sibling = children[idx + 1];

       child->keys[child->n] = keys[idx];

       if (!child->leaf) {
           child->children[child->n + 1] = sibling->children[0];
       }

       keys[idx] = sibling->keys[0];

       for (int i = 1; i < sibling->n; i++) {
           sibling->keys[i - 1] = sibling->keys[i];
       }

       if (!sibling->leaf) {
           for (int i = 1; i <= sibling->n; i++) {
               sibling->children[i - 1] = sibling->children[i];
           }
       }

       child->n += 1;
       sibling->n -= 1;
   }

   void merge(int idx) {
       BTreeNode *child = children[idx];
       BTreeNode *sibling = children[idx + 1];

       child->keys[t - 1] = keys[idx];

       for (int i = 0; i < sibling->n; i++) {
           child->keys[i + t] = sibling->keys[i];
       }

       if (!child->leaf) {
           for (int i = 0; i <= sibling->n; i++) {
               child->children[i + t] = sibling->children[i];
           }
       }

       for (int i = idx + 1; i < n; i++) {
           keys[i - 1] = keys[i];
       }

       for (int i = idx + 2; i <= n; i++) {
           children[i - 1] = children[i];
       }

       child->n += sibling->n + 1;
       n--;

       delete sibling;
   }
};

class BTree {
public:
    BTreeNode *root;
    int t;

    BTree(int _t) : root(nullptr), t(_t) {}

    void traverse() {
        if (root != nullptr) {
            root->traverse();
        }
    }

    BTreeNode* search(int k) {
        return root == nullptr ? nullptr : root->search(k);
    }

    void insert(int k) {
        if (root == nullptr) {
            root = new BTreeNode(t, true);
            root->keys[0] = k;
            root->n = 1;
        } else {
            if (root->n == 2 * t - 1) {
                BTreeNode *s = new BTreeNode(t, false);
                s->children[0] = root;
                s->splitChild(0);

                int i = 0;
                if (s->keys[0] < k) {
                    i++;
                }
                s->children[i]->insertNonFull(k);
                root = s;
            } else {
                root->insertNonFull(k);
            }
        }
    }

    void remove(int k) {
        if (!root) {
            cout << "The tree is empty." << endl;
            return;
        }

        root->remove(k);

        if (root->n == 0) {
            BTreeNode *tmp = root;
            root = root->leaf ? nullptr : root->children[0];
            delete tmp;
        }
    }
};

int main() {
    BTree t(3);

    int choice, key;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Remove\n";
        cout << "3. Search\n";
        cout << "4. Traverse\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                t.insert(key);
                break;
            case 2:
                cout << "Enter key to remove: ";
                cin >> key;
                t.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                if(t.search(key)) 
                    cout << "Key " << key << " found." << endl;
                else 
                    cout << "Key " << key << " not found." << endl;
                break;
            case 4:
                cout << "Traversal of the tree: ";
                t.traverse();
                cout << endl;
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 5);

    return 0;
}

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// Структура абонента
struct Subscriber {
    string name;
    int phoneNumber;
    string tariff;
};

enum Color { RED, BLACK };

class RBNode {
public:
    int key;
    Subscriber data;
    Color color = RED;
    RBNode* left = nullptr;
    RBNode* right = nullptr;
    RBNode* parent = nullptr;
    
    RBNode(int k, const Subscriber& d) : key(k), data(d) {}
};

class RedBlackTree {
private:
    RBNode* root = nullptr;

    void rotateLeft(RBNode* x);
    void rotateRight(RBNode* y);
    void insertFixup(RBNode* z);
    void deleteFixup(RBNode* x);
    RBNode* minimum(RBNode* node);
    void transplant(RBNode* u, RBNode* v);
    bool isRed(RBNode* node) { return node && node->color == RED; }
    void inOrderTraversal(RBNode* node);
    void printTree(RBNode* node, int depth = 0);

public:
    ~RedBlackTree();
    void insert(const Subscriber& sub);
    Subscriber search(int number);
    void printAll(); // выводит всю базу данных
    map<string, int> countTariffs(); // возвращает статистику тарифов
};

void RedBlackTree::rotateLeft(RBNode* x) {
    RBNode* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr) this->root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void RedBlackTree::rotateRight(RBNode* y) {
    RBNode* x = y->left;
    y->left = x->right;
    if (x->right != nullptr) x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == nullptr) this->root = x;
    else if (y == y->parent->right) y->parent->right = x;
    else y->parent->left = x;
    x->right = y;
    y->parent = x;
}

void RedBlackTree::insertFixup(RBNode* z) {
    while (z != root && isRed(z->parent)) {
        if (z->parent == z->parent->parent->left) {
            RBNode* uncle = z->parent->parent->right;
            if (isRed(uncle)) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(z->parent->parent);
            }
        } else {
            RBNode* uncle = z->parent->parent->left;
            if (isRed(uncle)) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::deleteFixup(RBNode* x) {
    while (x != root && !isRed(x)) {
        if (x == x->parent->left) {
            RBNode* w = x->parent->right;
            if (isRed(w)) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft(x->parent);
                w = x->parent->right;
            }
            if (!isRed(w->left) && !isRed(w->right)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (!isRed(w->right)) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rotateRight(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                rotateLeft(x->parent);
                x = root;
            }
        } else {
            RBNode* w = x->parent->left;
            if (isRed(w)) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight(x->parent);
                w = x->parent->left;
            }
            if (!isRed(w->right) && !isRed(w->left)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (!isRed(w->left)) {
                    w->right->color = BLACK;
                    w->color = RED;
                    rotateLeft(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rotateRight(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

RBNode* RedBlackTree::minimum(RBNode* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}

void RedBlackTree::transplant(RBNode* u, RBNode* v) {
    if (u->parent == nullptr) root = v;
    else if (u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    if (v != nullptr) v->parent = u->parent;
}

Subscriber RedBlackTree::search(int number) {
    RBNode* current = root;
    while (current != nullptr && current->key != number) {
        if (number < current->key) current = current->left;
        else current = current->right;
    }
    return current ? current->data : Subscriber{"Not found", -1, ""};
}

void RedBlackTree::insert(const Subscriber& sub) {
    RBNode* newNode = new RBNode(sub.phoneNumber, sub);
    RBNode* y = nullptr;
    RBNode* x = root;
    while (x != nullptr) {
        y = x;
        if (newNode->key < x->key) x = x->left;
        else x = x->right;
    }
    newNode->parent = y;
    if (y == nullptr) root = newNode;
    else if (newNode->key < y->key) y->left = newNode;
    else y->right = newNode;
    insertFixup(newNode);
}

void RedBlackTree::printAll() {
    cout << "Database contents:\n";
    inOrderTraversal(root);
    cout << "Tree:\n";
    printTree(root);
}

void RedBlackTree::inOrderTraversal(RBNode* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        cout << "Phone Number: " << node->data.phoneNumber << ", Name: " << node->data.name << ", Tariff: " << node->data.tariff << "\n";
        inOrderTraversal(node->right);
    }
}

void RedBlackTree::printTree(RBNode* node, int depth) {
    if (node == nullptr) return;

    printTree(node->right, depth + 1);

    for (int i = 0; i < depth; ++i) {
        cout << "    ";
    }

    cout << "Depth: " << depth << " Value: " << node->key << " Color: " << node->color << endl;

    printTree(node->left, depth + 1);
}


map<string, int> RedBlackTree::countTariffs() {
    map<string, int> result;

    function<void(RBNode*)> traverse = [&](RBNode* node) {
        if (node == nullptr) return;
        traverse(node->left);
        result[node->data.tariff]++;
        traverse(node->right);
    };

    traverse(root);
    
    return result;
}

RedBlackTree::~RedBlackTree() {
    function<void(RBNode*)> destroy = [=](RBNode* node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    };
    destroy(root);
}

void Test() 
{
    RedBlackTree tree;

    vector<Subscriber> subscribers = {
        {"A", 123456789, "Standard"},
        {"B", 987654321, "Premium"},
        {"C", 555555555, "Basic"},
        {"D", 111111111, "Standard"}
    };

    for (const auto& sub : subscribers) {
        tree.insert(sub);
    }

    int searchNumber = 123456789;
    Subscriber searchedSub = tree.search(searchNumber);
    if (searchedSub.name == "A" && searchedSub.tariff == "Standard") {cout << "SearchTest : True" << endl;}
    else{ cout << "SearchTest : False" << endl;}

    map<string, int> tariffStats = tree.countTariffs();
    pair<string, int> mostPopular("", 0);
    for (const auto& entry : tariffStats) {
        if (entry.second > mostPopular.second) {
            mostPopular.first = entry.first;
            mostPopular.second = entry.second;
        }
    }
    if (mostPopular.first == "Standard" && mostPopular.second == 2) {cout << "PopularTest : True" << endl;}
    else{ cout << "PopularTest : False" << endl;}

}

int main() {
    
    Test();

    RedBlackTree tree;

    vector<Subscriber> subscribers = {
        {"A", 123456789, "Standard"},
        {"B", 987654321, "Premium"},
        {"C", 555555555, "Basic"},
        {"D", 111111111, "Standard"}
    };

    for (const auto& sub : subscribers) {
        tree.insert(sub);
    }

    tree.printAll();

    int searchNumber = 123456789;
    Subscriber searchedSub = tree.search(searchNumber);
    cout << "Search by Phone Number (" << searchNumber << "):\nName: "
         << searchedSub.name << ", Tariff: " << searchedSub.tariff << endl;

    map<string, int> tariffStats = tree.countTariffs();
    pair<string, int> mostPopular("", 0);
    for (const auto& entry : tariffStats) {
        if (entry.second > mostPopular.second) {
            mostPopular.first = entry.first;
            mostPopular.second = entry.second;
        }
    }
    cout << "Most popular tariff: " << mostPopular.first << " with " << mostPopular.second << " users." << endl;

    return 0;
}
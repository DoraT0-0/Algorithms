class BinaryTree:
    def __init__(self, data = None, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right
    
    def printTree(self, x = 0):
        if self.left:
            self.left.printTree(x+1)
        print(f'{x} -', self.data)
        if self.right:
            self.right.printTree(x+1)
    def predecessorTree(self, x):
        if x < self.data:
            if self.left is None:
                return False
            print(self.data)
            return self.left.predecessorTree(x)
        elif x > self.data:
            if self.right is None:
                return False
            print(self.data)
            return self.right.predecessorTree(x)
        else:
            return True
    def insert(self, data):
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = BinaryTree(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = BinaryTree(data)
                else:
                    self.right.insert(data)
            else:
                return
        else:
            self.data = data

arr = [1,2,4,5,7,8,9,12]
tree = BinaryTree()
def fillTree(arr):
    n = len(arr)//2
    l, r = arr[:n], arr[n+1:] 
    tree.insert(arr[n])
    if len(l) >= 1:
        fillTree(l)
    if len(r) >= 1:
        fillTree(r)
fillTree(arr)

tree.printTree()
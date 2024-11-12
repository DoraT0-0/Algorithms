class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoubleLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    def append(self, data):
        if self.head == None:
            self.head = Node(data)
            self.tail = self.head
            return
        self.tail.next = Node(data)
        self.tail.next.prev = self.tail
        self.tail = self.tail.next
    
    def print_list(self):
        cur = self.head
        while cur:
            print(cur.data)
            cur = cur.next

l = DoubleLinkedList()
l.append(1)
l.append(5)
l.append(3)

l.print_list()

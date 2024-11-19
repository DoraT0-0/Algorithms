class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

def add_to_array(head):
    current = head
    arr = []
    while current is not None:
        arr.append(current.val)
        current = current.next
    return arr

def give_num(head):
    l = ''
    current = head
    while current is not None:
        l += str(current.val)
        current = current.next
    return int(l[::-1])

def add(head, x):
    new_node = ListNode(x)
    new_node.next = head
    head = new_node
    return head

def create_linked_list(i : int):
    s = str(i)
    l3 = ListNode(int(s[0]))
    for i in range(1, len(s)):
        l3 = add(l3, int(s[i]))
    return l3

l1 = ListNode(2, ListNode(4, ListNode(3)))
l2 = ListNode(5, ListNode(6, ListNode(4)))
l3 = create_linked_list(give_num(l1) + give_num(l2))
print(add_to_array(l3))


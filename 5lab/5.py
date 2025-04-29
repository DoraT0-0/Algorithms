import sys
input = sys.stdin.read


class SegmentTreeNode:
    def __init__(self):
        self.sum = 0
        self.best_sum = float('inf')
        self.prefix_min = float('inf')
        self.suffix_min = float('inf')


def build_tree(node_id, left, right, arr):
    if left == right:
        nodes[node_id].sum = arr[left]
        nodes[node_id].best_sum = min(arr[left], 0)
        nodes[node_id].prefix_min = min(arr[left], 0)
        nodes[node_id].suffix_min = min(arr[left], 0)
    else:
        mid = (left + right) // 2
        build_tree(2 * node_id + 1, left, mid, arr)
        build_tree(2 * node_id + 2, mid + 1, right, arr)
        
        combine_nodes(nodes[node_id], nodes[2*node_id+1], nodes[2*node_id+2])


def update_tree(node_id, left, right, idx, value):
    if left == right:
        nodes[node_id].sum = value
        nodes[node_id].best_sum = min(value, 0)
        nodes[node_id].prefix_min = min(value, 0)
        nodes[node_id].suffix_min = min(value, 0)
    else:
        mid = (left + right) // 2
        if idx <= mid:
            update_tree(2 * node_id + 1, left, mid, idx, value)
        else:
            update_tree(2 * node_id + 2, mid + 1, right, idx, value)
            
        combine_nodes(nodes[node_id], nodes[2*node_id+1], nodes[2*node_id+2])


def combine_nodes(parent_node, left_child, right_child):
    parent_node.sum = left_child.sum + right_child.sum

    parent_node.best_sum = min(
        left_child.best_sum,
        right_child.best_sum,
        left_child.suffix_min + right_child.prefix_min
    )
    
    parent_node.prefix_min = min(left_child.prefix_min, left_child.sum + right_child.prefix_min)

    parent_node.suffix_min = min(right_child.suffix_min, right_child.sum + left_child.suffix_min)


# data = input().strip()
data = '5 3\n1 -2 3 4 -5\n0 10\n1 -8\n4 7'
lines = data.split('\n')
n, m = map(int, lines[0].split())
arr = list(map(int, lines[1].split()))
queries = []
for line in lines[2:]:
    queries.append(list(map(int, line.split())))

nodes = [SegmentTreeNode() for _ in range(4*n)]
build_tree(0, 0, n-1, arr)

result = []

result.append(str(min(0, nodes[0].best_sum)))

for q in queries:
    index, new_value = q
    update_tree(0, 0, n-1, index, new_value)
    result.append(str(min(0, nodes[0].best_sum)))

print("\n".join(result))
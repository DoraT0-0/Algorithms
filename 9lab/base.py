import collections
from random import randint, choice
from typing import List, Dict, Tuple
from pprint import pprint

def add_edge(s: str, d: Tuple[str, int], adj_list: Dict[str, List]):
    adj_list[s].append(d)


nodes = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I']
adj_list = collections.defaultdict(list)
for node in nodes[:5]:
    for _ in range(randint(1, len(nodes))):
        dest_node = choice([n for n in nodes if n != node])
        weight = randint(50, 500)
        add_edge(node, (dest_node, weight), adj_list)


visited = set()
queue = collections.deque()
max_queue_size = 0
start_node = nodes[0]
queue.append(start_node)
visited.add(start_node)

while queue:
    max_queue_size = max(max_queue_size, len(queue))
    current_node = queue.popleft()
    
    for neighbor, _ in adj_list[current_node]:
        if neighbor not in visited:
            visited.add(neighbor)
            queue.append(neighbor)

print("Максимальная длина очереди:", max_queue_size)

weights_set = {weight for edges in adj_list.values() for _, weight in edges}

edges_to_remove = []
for weight in weights_set:
    matching_edges = [(src, dst) for src, neighbors in adj_list.items() for dst, w in neighbors if w == weight]
    seen = set()
    for edge in matching_edges:
        if edge in seen or (edge[1], edge[0]) in seen:
            edges_to_remove.append(edge)
        else:
            seen.add(edge)

for src, dst in edges_to_remove:
    for idx, (d, _) in enumerate(adj_list[src]):
        if d == dst:
            del adj_list[src][idx]
            break

pprint(dict(adj_list))
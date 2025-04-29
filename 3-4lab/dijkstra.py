import sys
 
class Graph(object):
    def __init__(self, nodes: list, init_graph):
        self.nodes = nodes
        self.graph = self.construct_graph(nodes, init_graph)
        
    def construct_graph(self, nodes, init_graph):
        graph = {}
        for node in nodes:
            graph[node] = {}
        
        graph.update(init_graph)
        
        for node, edges in graph.items():
            for adjacent_node, value in edges.items():
                if graph[adjacent_node].get(node, False) == False:
                    graph[adjacent_node][node] = value
                    
        return graph
    
    def add_nodes(self, node):
        self.nodes.append(node)
        self.graph = self.construct_graph(self.nodes, self.graph)
    
    def add_edge(self, one, two, value):
        self.graph[one][two] = value
        self.graph = self.construct_graph(self.nodes, self.graph)

    def get_nodes(self):
        return self.nodes
    
    def get_graph(self):
        return self.graph

    def get_outgoing_edges(self, node):
        connections = []
        for out_node in self.nodes:
            if self.graph[node].get(out_node, False) != False:
                connections.append(out_node)
        return connections
    
    def value(self, node1, node2):
        return self.graph[node1][node2]
    
    def BFS(self, s):
        visited = {}
        for node in self.nodes:
            visited[node] = False
        queue = []
        queue.append(s)
        visited[s] = True

        while queue:
            s = queue.pop(0)
            print(s, end=" ")
            n = self.get_outgoing_edges(s)
            for i in n:
                if not visited[i]:
                    queue.append(i)
                    visited[i] = True

    def DFSUtil(self, v, visited):
        visited.add(v)
        print(v, end=' ')
        n = self.get_outgoing_edges(v)
        for neighbour in n:
            if neighbour not in visited:
                self.DFSUtil(neighbour, visited)

    
    def DFS(self, v):
        visited = set()
        self.DFSUtil(v, visited)

def dijkstra_algorithm(graph, start_node):
    unvisited_nodes = list(graph.get_nodes())
 
    shortest_path = {}
    previous_nodes = {}
 
    max_value = sys.maxsize
    for node in unvisited_nodes:
        shortest_path[node] = max_value
    shortest_path[start_node] = 0
    
    while unvisited_nodes:
        current_min_node = None
        for node in unvisited_nodes:
            if current_min_node == None:
                current_min_node = node
            elif shortest_path[node] < shortest_path[current_min_node]:
                current_min_node = node
                
        neighbors = graph.get_outgoing_edges(current_min_node)
        for neighbor in neighbors:
            tentative_value = shortest_path[current_min_node] + graph.value(current_min_node, neighbor)
            if tentative_value < shortest_path[neighbor]:
                shortest_path[neighbor] = tentative_value
                previous_nodes[neighbor] = current_min_node
 
        unvisited_nodes.remove(current_min_node)
    
    return previous_nodes, shortest_path


def print_matrix_adjacency(graph: Graph):
    print(" ", end=" ")
    for node in graph.get_nodes():
        print(node, end=" ")
    print()
    for node1 in graph.get_nodes():
        print(node1, end=" ")
        for node2 in graph.get_nodes():
            try:
                if graph.graph[node1][node2]:
                    print(graph.graph[node1][node2], end=" ")
            except:
                print(0, end=" ")
        print(end="\n")

def print_list_adjacency(graph: Graph):
    for node1 in graph.graph:
        print(node1, end=": ")
        for node2 in graph.graph[node1]:
            print(f"({node2}, {graph.graph[node1][node2]})", end=" ")
        print()


def print_result(previous_nodes, shortest_path, start_node, target_node):
    path = []
    node = target_node
    
    while node != start_node:
        path.append(node)
        node = previous_nodes[node]

    path.append(start_node)
    print("Найден следующий лучший маршрут с ценностью {}.".format(shortest_path[target_node]))
    print(" -> ".join(reversed(path)))

# nodes = ["Reykjavik", "Oslo", "Moscow", "London", "Rome", "Berlin", "Belgrade", "Athens"]
# nodes = ["A", "B", "C"]
# init_graph = {}
# for node in nodes:
#     init_graph[node] = {}
    
# init_graph["A"]["B"] = 5
# init_graph["Reykjavik"]["London"] = 4
# init_graph["B"]["C"] = 1
# init_graph["Oslo"]["Moscow"] = 3
# init_graph["Moscow"]["Belgrade"] = 5
# init_graph["Moscow"]["Athens"] = 4
# init_graph["Athens"]["Belgrade"] = 1
# init_graph["Rome"]["Berlin"] = 2
# init_graph["Rome"]["Athens"] = 2

# graph = Graph(nodes, init_graph)


# print_matrix_adjacency(graph)

# previous_nodes, shortest_path = dijkstra_algorithm(graph=graph, start_node="Reykjavik")

# print_result(previous_nodes, shortest_path, start_node="Reykjavik", target_node="Moscow")
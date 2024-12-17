class Queue:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)


class Graph:
    def __init__(self):
        self.graph = {}
    
    def addNode(self, node_value):
        if node_value not in self.graph:
            self.graph[node_value] = []
    
    def addEdges(self, from_node, to_node):
        if from_node not in self.graph:
            self.addNode(from_node)
        if to_node not in self.graph:
            self.addNode(to_node)
        self.graph[from_node].append(to_node)
    
    def dfs(self, start_node, visited = None):
        if visited is None:
            visited = set()
        visited.add(start_node)
        result = [start_node]
        for n in self.graph[start_node]:
            if n not in visited:
                result.extend(self.dfs(n, visited))
        return result

    def dfsAll(self):
        visited = set()
        result = []

        for n in self.graph.keys():
            if n not in visited:
                dfs_result = self.dfs(n, visited)
                result.extend(dfs_result)
        return result


    def bfs(self, start_node):
        visited = set()
        queue = Queue()
        queue.enqueue(start_node)
        result = []
        while not queue.is_empty():
            node = queue.dequeue()
            if node not in visited:
                visited.add(node)
                result.append(node)
                for n in self.graph[node]:
                    if n not in visited:
                        queue.enqueue(n)
        return result

    def bfsAll(self):
        visited = set()
        result = []
        for node in self.graph.keys():
            if node not in visited:
                bfs_result = self.bfs(node)
                result.extend(bfs_result)
                visited.update(bfs_result)
        return result
    
    def printGraph(self):
        for node, neighbors in self.graph.items():
            print(f"{node}: {', '.join(neighbors)}")

    def restructurePlan(self, actions):
        for action1, count1 in actions:
            self.addNode(action1)
            for action2, count2 in actions:
                if action1 != action2 and count1 < count2:
                    self.addEdges(action1, action2)
    

g = Graph()

events = [
    ('A', 5),
    ('B', 10),
    ('C', 8),
    ('D', 15),
    ('G', 20)
]

g.restructurePlan(events)

g.printGraph()

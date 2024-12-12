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
        self.count = {}

    def InGraph(self, node):
        if node not in self.graph.keys():
            return 1
        
    def addNode(self, node, count = 0):
        if node not in self.graph:
            self.graph[node] = []
            self.count[node] = count
    
    def addEdges(self, from_node, to_node):
        self.graph[from_node].append(to_node)
    
    def dfs(self, start_node: tuple, visited = None):
        if visited is None:
            visited = set()
        visited.add(start_node)
        result = [start_node]
        for n in self.graph[start_node]:
            if n not in visited:
                result.extend(self.dfs(n, visited))
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
    
    def printGraph(self):
        for node, neighbors in self.graph.items():
            print(f"{node} ({self.count[node]}): {','.join(neighbors)}")

    def restructurePlan(self):
        graph2 = Graph()
        for action1 in self.graph:
            graph2.addNode(action1, self.count[action1])
            for action2 in self.graph:
                graph2.addNode(action2, self.count[action2])
                if action1 != action2 and self.count[action1] < self.count[action2]:
                    graph2.addEdges(action1, action2)
        return graph2
    


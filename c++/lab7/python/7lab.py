from structGraphAndQueue import Graph
graph = Graph()

graph.graph = {
    'A' : ['B', 'C'],
    'B' : ['A'],
    'C' : ['B']
}
graph.count = { 
    'A' : 10,
    'B' : 20,
    'C' : 5
}

def showGraph():
    print("-"*30)
    print("Текущий список смежности графа:")
    graph.printGraph()
    print("-"*30)

def addNodeInGraph():
    print("-"*30)
    countNode: int
    nameNode = input("Введите название вершины:")
    while True:
        countNode = input("Введите кол-во участников вершины:")
        if countNode == '0': menu()
        if countNode.isdigit() == False: print("Введите число")
        else: break
    graph.addNode(nameNode, countNode)
    print("-"*30)

def addEdgeInGraph():
    nameNode1: str
    nameNode2: str
    print("-"*30)
    while True:
        nameNode1 = input("Введите название первой вершины:")
        if nameNode1 == '0': menu()
        if graph.InGraph(nameNode1): print("Такой вершины нет, попробуйте ещё раз")
        else: break
    while True:
        nameNode2 = input("Введите название второй вершины:")
        if nameNode2 == '0': menu()
        if graph.InGraph(nameNode2): print("Такой вершины нет, попробуйте ещё раз")
        else: break

    graph.addEdges(nameNode1, nameNode2)
    print("-"*30)
    
def bfs():
    nameNode: str
    print("-"*30)
    print("Обход в ширину")
    while True:
        nameNode = input("Введите название вершины:")
        if nameNode == '0': menu()
        if graph.InGraph(nameNode): print("Такой вершины нет, попробуйте ещё раз")
        else: break
    print(graph.bfs(nameNode))
    print("-"*30)

def dfs():
    nameNode: str
    print("-"*30)
    print("Обход в глубину")
    while True:
        nameNode = input("Введите название вершины:")
        if nameNode == '0': menu()
        if graph.InGraph(nameNode): print("Такой вершины нет, попробуйте ещё раз")
        else: break
    print(graph.dfs(nameNode))
    print("-"*30)

def restructurePlan():
    print("-"*30)
    print("Переработанный список смежности графа:")
    graph.restructurePlan().printGraph()
    print("-"*30)
    

def menu():
    print("-"*30)
    print("Выберите действие:\n", 
          "1. Добавить вершину\n",
          "2. Добавить ребро\n",
          "3. Показать список смежности графа\n",
          "4. Обход графа в ширину\n",
          "5. Обход графа в глубину\n",
          "6. Переработать граф с учётом плана\n",
          "0. Завершить работу программы\n",
          )
    
    action = input("Введите номер действия:")
    match action:
        case '0':
            exit()
        case '1': 
            addNodeInGraph()
            menu()
        case '2':
            addEdgeInGraph()
            menu()
        case '3':
            showGraph()
            menu()
        case '4':
            bfs()
            menu()
        case '5':
            dfs()
            menu()
        case '6':
            restructurePlan()
            menu()
        case _:
            print("Попробуйте ещё раз\n")
            menu()
    
menu()





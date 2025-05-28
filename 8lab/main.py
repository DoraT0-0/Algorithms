from dijkstra import *



menu_choice = None
graph = Graph(['A', 'B', 'C', 'D'], {'A': {'B': 6}, 'B': {'A': 6, 'C': 7, 'D': 8}, 'C': {'B': 7}, 'D': {'B': 8}})

while menu_choice != '0':
    print("\nМеню:\n"
            "1. Добавить узел\n"
            "2. Добавить ребро\n"
            "3. Вывести граф\n"
            "4. Обход графа\n"
            "5. Алгоритм Дейстра для текущего графа\n"
            "6. Определить кол-во путей с определённым количеством пересадок\n"
            "0. Выход")
    
    menu_choice = input("Выберите пункт меню: ")
    
    if menu_choice == '1':
        graph.add_nodes(input("Введите назвние узла:"))
        print(graph.get_nodes())
            
    elif menu_choice == '2':
        graph.add_edge(input("Введите назвние первого узла:"), input("Введите назвние второго узла:"), int(input("Введите вес ребра:")))
        print(graph.get_graph())

    elif menu_choice == '3':
        choice = input("0 - матрица смежности, 1 - список смежности :")
        if choice == '0': print_matrix_adjacency(graph)
        elif choice == '1': print_list_adjacency(graph)
        else: "error"

    elif menu_choice == '4':
        choice = input("0 - DFS, 1 - BFS :")
        target = input("Введите название вершины: ")
        if choice == '0': graph.DFS(target)
        elif choice == '1': graph.BFS(target)
        else: "error"

    elif menu_choice == '5':
        start_node = input("Введите название первой вершины графа (стартовой): ")
        target_node = input("Введите название второй вершины графа (конечной): ")
        previous_nodes, shortest_path = dijkstra_algorithm(graph, start_node)
        print_result(previous_nodes, shortest_path, start_node, target_node)
        
    elif menu_choice == '6':
        start_node = input("Введите название первой вершины графа (стартовой): ")
        target_node = input("Введите название второй вершины графа (конечной): ")
        max_transfers = input("Введите максимальное количество пересадок: ")
        result_paths = find_all_paths_with_fixed_transfers(graph, start_node, target_node, max_transfers)
        for p in result_paths:
            print(p)

    elif menu_choice == '0':
        print("Завершение работы...")
    else:
        print("Некорректный выбор пункта меню!")
class Node:
    def __init__(self, symbol=None, frequency=0, left=None, right=None):
        self.symbol = symbol      # Символ (для листьев)
        self.frequency = frequency  # Частота символа
        self.left = left           # Левое поддерево
        self.right = right         # Правое поддерево

    def __repr__(self):
        return f'Node({self.symbol}, {self.frequency})'


def build_shannon_fano_tree(symbols):
    nodes = [Node(sym, freq) for sym, freq in symbols]
    nodes.sort(key=lambda n: n.frequency, reverse=True)

    def divide_nodes(nodes_list):
        total_freq = sum(node.frequency for node in nodes_list)
        target_half = total_freq // 2
        cumulative_freq = 0
        i = 0
        while cumulative_freq < target_half and i < len(nodes_list):
            cumulative_freq += nodes_list[i].frequency
            i += 1
        return nodes_list[:i], nodes_list[i:]

    def recursive_build(nodes_list):
        if len(nodes_list) == 1:
            return nodes_list[0]
        left_nodes, right_nodes = divide_nodes(nodes_list)
        left_child = recursive_build(left_nodes)
        right_child = recursive_build(right_nodes)
        parent_node = Node(frequency=(left_child.frequency + right_child.frequency),
                           left=left_child,
                           right=right_child)
        return parent_node

    root = recursive_build(nodes)
    return root


def generate_codes(root, prefix='', codes={}):
    if root.symbol is not None:
        codes[root.symbol] = prefix
    else:
        generate_codes(root.left, prefix+'0', codes)
        generate_codes(root.right, prefix+'1', codes)
    return codes


def display_tree(root, indent=''):
    if root.symbol is not None:
        print(indent + "- " + str(root.symbol) + ": " + str(root.frequency))
    else:
        print(indent + "+ (" + str(root.frequency) + ")")
        display_tree(root.left, indent + '| ')
        display_tree(root.right, indent + '| ')



def calculate_compression_ratio(original_data, encoded_data):
    original_size_bits = len(original_data) * 8 
    compressed_size_bits = len(encoded_data)
    compression_ratio = round(compressed_size_bits / original_size_bits * 100, 2)
    size_reduction_percentage = round((original_size_bits - compressed_size_bits) / original_size_bits * 100, 2)
    return f"{compression_ratio}% ({size_reduction_percentage}% сокращение)"


def input_from_file(file_name):
    try:
        with open(file_name, 'r') as file:
            data = file.read().strip()
        print(f"Данные успешно загружены из файла {file_name}.")
        return data
    except FileNotFoundError:
        print("Ошибка! Файл не найден.")
        return None


def input_from_console():
    user_input = []
    print("Введите данные по одному символу за раз, завершив ввод цифрой 0:")
    while True:
        char = input("Следующий символ: ")
        if char == '0':
            break
        user_input.append(char)
    return ''.join(user_input)


def encode_and_output(data, output_filename="output.txt"):
    frequencies = {}
    for char in data:
        frequencies[char] = frequencies.get(char, 0) + 1
    
    coded_symbols = list(frequencies.items())
    tree_root = build_shannon_fano_tree(coded_symbols)
    codes = generate_codes(tree_root)
    
    encoded_data = ''.join([codes[ch] for ch in data])
    
    print("\nТаблица кодирования:")
    headers = ["Символ", "Частота", "Код"]
    rows = [[symbol, freq, codes[symbol]] for symbol, freq in frequencies.items()]
    row_format = "{:^10}" * len(headers)
    print(row_format.format(*headers))
    for row in rows:
        print(row_format.format(*row))
    
    print("\nИсходная длина:", len(data), "символов.")
    print("Длина закодированного сообщения:", len(encoded_data), "бит.")
    print("Коэффициент сжатия:", calculate_compression_ratio(data, encoded_data))
    
    print("\nДерево кодирования Шеннона-Фано:")
    display_tree(tree_root)
    
    write_to_file = input("\nЗаписать результат в файл (y/n)? ").lower() == 'y'
    if write_to_file:
        with open(output_filename, 'w') as out_file:
            out_file.write(encoded_data)
        print(f"\nЗакодированные данные записаны в файл '{output_filename}'.")
    else:
        print(f"\nЗакодированное сообщение: {encoded_data}")
        print("\nРезультат не сохранён в файле.")


if __name__ == "__main__":
    output_file = "encoded_data.txt"
    menu_choice = ''
    
    while menu_choice != '4':
        print("\nМеню:\n"
              "1. Загрузить данные из файла\n"
              "2. Ввести данные вручную\n"
              "3. Изменить имя выходного файла\n"
              "4. Выход")
        
        menu_choice = input("Выберите пункт меню: ")
        
        if menu_choice == '1':
            filename = input("Укажите путь к файлу: ")
            data = input_from_file(filename)
            if data is not None:
                encode_and_output(data, output_file)
                
        elif menu_choice == '2':
            data = input_from_console()
            encode_and_output(data, output_file)
            
        elif menu_choice == '3':
            new_filename = input("Введите новое имя выходного файла: ")
            output_file = new_filename
            print(f"Имя выходного файла изменено на '{new_filename}'")
            
        elif menu_choice == '4': 
            print("Завершение работы...")
        else:
            print("Некорректный выбор пункта меню!")
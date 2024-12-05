def Count_El_del_5_and_2(arr):
    count = 0
    for num in arr:
        if num % 2 == 0 and num % 5 == 0:
            count += 1
    return count

def test_count_el_del_5_and_2():
    # Тест 1: Пустой массив
    result = Count_El_del_5_and_2([])
    assert result == 0, f"Expected 0 but got {result}"

    # Тест 2: Нет элементов, соответствующих критериям
    result = Count_El_del_5_and_2([1, 3, 7, 9])
    assert result == 0, f"Expected 0 but got {result}"

    # Тест 3: Один элемент, соответствующий критериям
    result = Count_El_del_5_and_2([10])
    assert result == 1, f"Expected 1 but got {result}"
    result = Count_El_del_5_and_2([4])
    assert result == 0, f"Expected 0 but got {result}"

    # Тест 4: Несколько элементов, соответствующих критериям
    result = Count_El_del_5_and_2([10, 20, 30])
    assert result == 3, f"Expected 3 but got {result}"
    result = Count_El_del_5_and_2([10, 15, 20, 25])
    assert result == 2, f"Expected 2 but got {result}"

    print("Все тесты прошли успешно!")

test_count_el_del_5_and_2()


# arr = []
# while True:
#     n = int(input("Введите целое число: "))
#     if n == 0: break
#     arr.append(n)
# print("Кол-во чётных элементов кратных 5: ", Count_El_del_5_and_2(arr))
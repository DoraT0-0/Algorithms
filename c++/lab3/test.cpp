#include <iostream>
#include <time.h>
struct Matrix {
	int n; // количество строк
	int m; // количество столбцов
	int **arr; // указатель на двумерный массив
};
Matrix initNM(void)
	// функция введение размерность матрицы
	// вход: -
	// выход: размерность матрицы
{
	Matrix A;
	std::cout << "Vvod n = "; std::cin >> A.n;
	std::cout << "Vvod m = "; std::cin >> A.m;
	return A;
}
Matrix createT(Matrix A)
	// функция выделения динамической памяти для матрицы
	// вход: матрицы
	//выход: выделенная память для матрицы
{
	A.arr = new int*[A.n];
	for (int i = 0; i < A.n; i++)
		A.arr[i] = new int[A.m];
	return A;
}
void initArr(Matrix A)
	// функция инициализации матрицы
	// вход: пустая матрица
	// выход: матрицы из заполненных значений
{
	for (int i = 0; i < A.n; i++)
		for (int j = 0; j < A.m; j++)
			A.arr[i][j] = rand() % 2;
}
Matrix Processing0(Matrix A)
// функция транспонирования матрицы
// вход: матрица значений
// выход: транспонированная матрица
{
	Matrix T;
	T.n=A.n;T.m = A.m;
	T = createT(T);
	for (int i = 0; i < A.n; i++)
		for (int j = 0; j < A.m; j++)
			T.arr[i][j] = A.arr[j][i];
	return T;
}
void show(Matrix A)
// функция вывода матрицы на экран
// вход: матрица значений
// выход: значение матрицы на консоли
{
	for (int i = 0; i < A.n; i++)
	{
		for (int j = 0; j < A.m; j++)
		    std::cout << A.arr[i][j]<<" ";
		    std::cout << "\n";
	}
	std::cout << "\n \n";
}
void del(Matrix A)
// функция удаления матрицы из памяти
// вход: матрица значений
//выход: удаленная матрица
{
	for (int і = 0; і < A.m; і++)
		delete[] A.arr[і];
	delete[] A.arr;
}
int main()
{
	Matrix A;
	srand(time(0));
	A = initNM();
	A = createT(A);
	initArr(A);
	show(A);
	A=Processing0(A);
	show(A);
	del(A);
	system("pause");
}

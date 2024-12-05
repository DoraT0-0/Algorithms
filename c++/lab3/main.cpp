#include <iostream>
#include <time.h>
#include <cstdlib>

struct Matrix {
    int n;
    int m;
    int **arr;
};
Matrix initNM(void){
    Matrix A;
    std::cout << "Vvod n = "; std::cin >> A.n;
    std::cout << "Vvod m = "; std::cin >> A.m;
    return A;
}
Matrix create(Matrix A){
    A.arr = new int*[A.n];
    for (int i = 0; i < A.n; i++)
        A.arr[i] = new int[A.m];
    return A;
}

void initArr(Matrix A)
{
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
            A.arr[i][j] = rand() % 2;
}

Matrix Processing0(Matrix A){
    Matrix T;
    T.n= A.n; T.m = A.m;
    T = create(T);
    for (int i = 0; i < A.n; i++)
        for (int j = 0; j < A.m; j++)
            T.arr[i][j] = A.arr[j][i];
    return T;
}

void show(Matrix A){
    for (int i = 0; i < A.n; i++)
    {
        for (int j = 0; j < A.m; j++)
        std::cout << A.arr[i][j]<<" ";
        std::cout << "\n";
    }
    std::cout << "\n \n";
}

void del(Matrix A){
    for (int j = 0; j < A.m; j++)
        delete[] A.arr[j];
    delete[] A.arr;
}


void testMatrixFunctions() {
    srand(time(0));

    cout << L"Тест 1: Создание и инициализация матрицы 3x3" << std::endl;
    Matrix A;
    A.n = 3;
    A.m = 3;
    A = create(A);
    initArr(A);
    show(A);

    cout << L"Тест 2: Транспонирование матрицы" << std::endl;
    Matrix T = Processing0(A);
    show(T);

    del(A);
    del(T);
}




int main(){
    // Matrix A;
    // srand(time(0));
    // A = initNM();
    // A = create(A);
    // initArr(A);
    // show(A);
    // A=Processing0(A);
    // show(A);
    // del(A);
    setlocale(LC_ALL, "");
    testMatrixFunctions();
    system("pause");
}
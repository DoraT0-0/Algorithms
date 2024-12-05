#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct Matrix
{
    double* matrix;
    int rows, columns;
};

Matrix* create_matrix(int rows, int cols){
    Matrix* matrix = new Matrix[sizeof(Matrix)];
    matrix->rows = rows;
    matrix->columns = cols;
    matrix->matrix = new double[rows * cols];
    return matrix;
}

Matrix* init_matrix(double* data, int rows, int cols){
    Matrix* matrix = create_matrix(rows, cols);
    for(int i = 0; i < rows*cols; i++){
        matrix->matrix[i] = data[i];
    }
    return matrix;
}


double* randomlFiling(int r, int c){
    double* a = new double[r*c];
    int max = 3.3, min = -3.3;
    for(int i = 0;i < r*c;i++){
        a[i] = min + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (max - min)));
    }
    return a;
}

Matrix user_inputNM_and_createMatrix(){
    int r, c;
    do{
        cout << "Input count rows (3-10).0 - exit: ";
        cin >> r;
        if(r == 0) exit(0);
    }while (r < 3 or r > 10);
    do{
        cout << "Input count cols (3-10).0 - exit: ";
        cin >> c;
        if(c == 0) exit(0);
    }while (c < 3 or c > 10);
    Matrix* m = init_matrix(randomlFiling(r, c), r, c);
    return *m;
} 

double* summ_elem(Matrix *matrix){
    int rows = matrix->rows;
    double* summ_all = new double[rows];
    for(int x = 0; x < matrix->rows; x++){
        for(int y = 0; y < matrix->columns; y++){
            summ_all[x] += matrix->matrix[x*(matrix->columns) + y];
        }
    }
    return summ_all;
}

void print_matrix(Matrix* m){
    cout << fixed << setprecision(3);
    cout <<endl << "\t\t" << "Matrix:";
    for(int x = 0; x < m->rows; x++) {
        cout << "\n";
        for(int y = 0; y < m->columns; y++) {
            cout << "\t" << m->matrix[x*(m->columns) + y];
        }
    }
    cout << endl;
}

void clear_ram(Matrix* matrix){
    delete [] matrix;
}

int main(){
    srand(time(0));

    Matrix A = user_inputNM_and_createMatrix();
    print_matrix(&A);
    cout << endl << "B = [ ";
    double* B = summ_elem(&A);
    for(int i = 0;i < m.rows;i++){
        cout << B[i] << " ";
    };
    cout << "]" << endl;

    system("pause");
}
#include <iostream>
#include <cstdlib> 
using namespace std;

struct Matrix
{
    double* matrix;
    int rows, columns;
};

// CREATE MATRIX

Matrix* fill_null_matrix(int rows, int cols){
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->columns = cols;
    double* data = (double*)malloc(rows * cols * sizeof(double));
    matrix->matrix = data;
    free(data);
    return matrix;
}

Matrix* create_matrix(double* data, int rows, int cols){
    Matrix* matrix = fill_null_matrix(rows, cols);
    for(int i = 0; i < rows*cols; i++){
        matrix->matrix[i] = data[i];
    }
    return matrix;
}

// FILLING MATRIX

double* manualFiling(int r, int c){
    double* a = (double*)malloc(sizeof(double) * r * c);
    for(int i = 0;i < r*c;i++){
        cout << "Input [" << i << "]: "; 
        cin >> a[i];
    }
    return a;
}

double* randomlFiling(int r, int c){
    double* a = (double*)malloc(sizeof(double) * r * c);
    int max = 1000, min = -1000;
    for(int i = 0;i < r*c;i++){
        a[i] = rand() % (max - min + 1) + min;;
    }
    return a;
}

Matrix user_input(){
    int r, c, mode;
    cout << "Input count rows: ";
    cin >> r;
    cout << "Input count cols: ";
    cin >> c;
    cout << "Filling mode: 0.keyboard 1.randomize :";
    cin >> mode;
    double* a = mode ? randomlFiling(r, c) : manualFiling(r, c);
    Matrix* m = create_matrix(a, r, c);
    free(a);
    return *m;
} 

// PROCESSING

double* summ_elem(Matrix *matrix){
    int cols = matrix->columns;
    double* summ_all = new double[cols];
    for(int x = 0; x < matrix->columns; x++){
        for(int y = 0; y < matrix->rows; y++){
            summ_all[x] += matrix->matrix[y*(matrix->rows) + x];
        }
    }
    return summ_all;
}

int search_max_cols(Matrix* m){
    double* summ = summ_elem(m);
    int max_index = 0;
    for(int i=1;i < m->columns;i++){
        if(summ[max_index] < summ[i])
            max_index = i;
    }
    free(summ);
    return max_index;
}

void sort_matrix(Matrix* m, int index_sort){
    int n = m->rows < m->columns ? m->rows : m->columns;

    double* sort_arr = (double*)malloc(sizeof(double) * m->columns* m->rows);
    for(int i = 0;i < n;i++) sort_arr[i] = 0;
    for(int x = index_sort; x < index_sort+1; x++) {
        for(int y = 0; y < n; y++) {
            sort_arr[y] = m->matrix[index_sort*(n) + y];
        }
    }
    for(int i = 0;i < n-1;i++){
        for(int j = 0;j < n-1-i;j++){
            if(sort_arr[j] > sort_arr[j+1]){
                double b = sort_arr[j];
                sort_arr[j] = sort_arr[j+1];
                sort_arr[j + 1] = b;
            }
        }
    }

    //for(int i = 0;i < m->rows;i++) cout << endl << sort_arr[i];

    for(int x = index_sort; x < index_sort+1; x++) {
        for(int y = 0; y < n; y++) {
            m->matrix[x*(n) + y] = sort_arr[y];
        }
    }
    free(sort_arr);
}

//15 task

int number_max_row(Matrix* matrix){
    int* arr_rows = (int*)malloc(sizeof(int) * matrix->rows);
    for(int i = 0; i < matrix->rows; i++) arr_rows[i] = 0;
    double curr;
    for(int i=0;i<matrix->columns; i++){
        for(int j=0;j<matrix->rows; j++){
            if(j==0) curr = matrix->matrix[i*(matrix->columns) + j];
            else{
                if(curr < matrix->matrix[i*(matrix->columns) + j]){
                    arr_rows[i] += 1;
                }
                curr = matrix->matrix[i*(matrix->columns) + j];
            }
        }
    }
    int max_index = 0;
    for(int i = 0;i < matrix->rows; i++){
        if(arr_rows[max_index] < arr_rows[i]) max_index = i;
    }

    return arr_rows[max_index] ? max_index : -1;
}

//SHOW

void print_matrix(Matrix* m){
    cout <<endl << "\t\t" << "Matrix:";
    for(int x = 0; x < m->rows; x++) {
        cout << "\n";
        for(int y = 0; y < m->columns; y++) {
            cout << "\t" << m->matrix[x*(m->columns) + y];
        }
    }
    cout << endl;
}

void print_info(Matrix m){
    cout << endl << "Max column: " << search_max_cols(&m) << endl;
    cout << "Max number row:  " << number_max_row(&m) << endl;
}
//DELETE

void clear_ram(Matrix* matrix){
    free(matrix);
}

//MAIN

int main(){
    Matrix m = user_input();
    print_matrix(&m);
    print_info(m);
    sort_matrix(&m, search_max_cols(&m));
    print_matrix(&m);
    print_info(m);

    system("pause");
    clear_ram(&m);
    return 0;
}
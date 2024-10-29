#include <iostream>
#include <cstdlib> 
using namespace std;

struct Matrix
{
    double* matrix;
    int rows, columns;
};

// CREATE MATRIX

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

// FILLING MATRIX

double* manualFiling(int r, int c){
    double* a = new double[r*c];
    for(int i = 0;i < r*c;i++){
        cout << "Input [" << i << "]: "; 
        cin >> a[i];
    }
    return a;
}

double* randomlFiling(int r, int c){
    double* a = new double[r*c];
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
    Matrix* m = mode ? init_matrix(randomlFiling(r, c), r, c) : init_matrix(manualFiling(r, c), r, c);
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
    delete summ;
    return max_index;
}

void sort_matrix(Matrix* m, int index_sort){
    int n = m->rows < m->columns ? m->rows : m->columns;

    double* sort_arr = new double[m->columns* m->rows];
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
    for(int x = index_sort; x < index_sort+1; x++) {
        for(int y = 0; y < n; y++) {
            m->matrix[x*(n) + y] = sort_arr[y];
        }
    }
    delete [] sort_arr;
}

//16 task

double summ_strok(Matrix* matrix, int index) {
    double summ_all = 0;
        for (int y = 0; y < matrix->rows; y++) {
            summ_all += matrix->matrix[index * (matrix->rows) + y];
        }
    return summ_all;
}


void count_el(Matrix *m, int* arr_rows, int* j) {
    *j = 0;
    for (int x = 0; x < m->columns; x++) {
        int count_plus = 0;
        int count_minus = 0;
        for (int y = 0; y < m->rows; y++) {
            if (m->matrix[x * (m->rows) + y] > 0) {
                count_plus++;
            }
            else { 
                count_minus++;
            }
        }
        if (count_plus > count_minus) {
            arr_rows[*j] = x;
            *j += 1;
        }
    }
}

double sdr_arf(Matrix* m) {
    int* arr_rows = new int[m->columns];
    int j;
    count_el(m, arr_rows, &j);
    double srd = 0;
    for (int i = 0;i < j; i++) {
        srd += summ_strok(m, arr_rows[i]);
    }
    double result = (double) srd / (double) j;
    delete [] arr_rows;
    return result;
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
    cout << "Average of positive rows:  " <<  sdr_arf(&m) << endl;
}
//DELETE

void clear_ram(Matrix* matrix){
    delete [] matrix;
}

//MAIN

int main(){
    Matrix m = user_input();
    print_matrix(&m);
    print_info(m);
    sort_matrix(&m, search_max_cols(&m));
    print_matrix(&m);
    print_info(m);

    clear_ram(&m);
    system("pause");
}
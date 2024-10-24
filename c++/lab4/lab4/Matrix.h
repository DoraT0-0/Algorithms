#pragma once

#include <cstdlib> 

struct Matrix {
	double* matrix;
	int rows, columns;
};

double* randomlFiling(int r, int c) {
	double* a = new double[r*c];
	int max = 1000, min = -1000;
	for (int i = 0;i < r * c;i++) {
		a[i] = rand() % (max - min + 1) + min;;
	}
	return a;
}

Matrix* fill_null_matrix(int rows, int cols) {
	Matrix* matrix = new Matrix;
	matrix->rows = rows;
	matrix->columns = cols;
	double* data = (double*)malloc(rows * cols * sizeof(double));
	matrix->matrix = data;
	return matrix;
}

Matrix* create_matrix(double* data, int rows, int cols) {
	Matrix* matrix = fill_null_matrix(rows, cols);
	for (int i = 0; i < rows * cols; i++) {
		matrix->matrix[i] = data[i];
	}
	return matrix;
}

Matrix user_input(int r, int c, int mode) {
	double* a = randomlFiling(r, c);
	Matrix* m = create_matrix(a, r, c);
	delete [] a;
	return *m;
}

double* summ_elem(Matrix* matrix) {
	int cols = matrix->columns;
	double* summ_all = new double[cols];
	for (int i = 0; i < cols; i++) summ_all[i] = 0;
	for (int x = 0; x < matrix->columns; x++) {
		for (int y = 0; y < matrix->rows; y++) {
			summ_all[x] += matrix->matrix[y * (matrix->rows) + x];
		}
	}
	return summ_all;
}

int search_max_cols(Matrix* m) {
	double* summ = summ_elem(m);
	int max_index = 0;
	for (int i = 1;i < m->columns;i++) {
		if (summ[max_index] < summ[i])
			max_index = i;
	}
	free(summ);
	return max_index;
}

void sort_matrix(Matrix* m, int index_sort) {
	int n = m->rows < m->columns ? m->rows : m->columns;

	double* sort_arr = (double*)malloc(sizeof(double) * m->columns* m->rows);
	for (int i = 0;i < n;i++) sort_arr[i] = 0;
	for (int x = index_sort; x < index_sort + 1; x++) {
		for (int y = 0; y < n; y++) {
			sort_arr[y] = m->matrix[index_sort * (n)+y];
		}
	}
	for (int i = 0;i < n - 1;i++) {
		for (int j = 0;j < n - 1 - i;j++) {
			if (sort_arr[j] > sort_arr[j + 1]) {
				double b = sort_arr[j];
				sort_arr[j] = sort_arr[j + 1];
				sort_arr[j + 1] = b;
			}
		}
	}
	for (int x = index_sort; x < index_sort + 1; x++) {
		for (int y = 0; y < n; y++) {
			m->matrix[x * (n)+y] = sort_arr[y];
		}
	}
	free(sort_arr);
}

int number_max_row(Matrix* matrix) {
	int* arr_rows = (int*)malloc(sizeof(int) * matrix->rows);
	for (int i = 0; i < matrix->rows; i++) arr_rows[i] = 0;
	double curr;
	for (int i = 0;i < matrix->columns; i++) {
		for (int j = 0;j < matrix->rows; j++) {
			if (j == 0) curr = matrix->matrix[i * (matrix->columns) + j];
			else {
				if (curr < matrix->matrix[i * (matrix->columns) + j]) {
					arr_rows[i] += 1;
				}
				curr = matrix->matrix[i * (matrix->columns) + j];
			}
		}
	}
	int max_index = 0;
	for (int i = 0;i < matrix->rows; i++) {
		if (arr_rows[max_index] < arr_rows[i]) max_index = i;
	}

	return arr_rows[max_index] ? max_index : -1;
}
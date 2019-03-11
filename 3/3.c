#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void add(int **a, int **b, int **c, int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

int** make2dArray(int rows, int cols) {
	int **x, i;

	x = (int**)malloc(sizeof(int*)*rows);

	for (int i = 0; i < rows; i++) {
		x[i] = (int*)malloc(sizeof(int)*cols);
	}
	return x;
}
int** init2dArray(int** x, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			*(*(x + i) + j) = i + j + 1;
		}
	}
	return x;
}
void print2dArray(int **x, int rows, int cols) {
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%3d ",*(*(x+i)+j));
		}
		puts("");
	}
}
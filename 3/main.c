#include<stdio.h>
#include<stdlib.h>
void main() {
	int **a, **b, **c;
	int rows, cols;
	printf("Enter row Size and column Size (ex) 3 4\n");
	scanf("%d%d", &rows, &cols);

	a = make2dArray(rows, cols);
	a = init2dArray(a, rows, cols);

	b = make2dArray(rows, cols);
	b = init2dArray(b, rows, cols);

	c = make2dArray(rows, cols);

	add(a, b, c, rows, cols);
	printf("matrix A\n");
	print2dArray(a, rows, cols);
	puts("");

	printf("matrix B\n");
	print2dArray(b, rows, cols);
	puts("");

	printf("matrix C\n");
	print2dArray(c, rows, cols);

}
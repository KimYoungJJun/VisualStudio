//2016114673 김영준
//본인은 이 소스파일을 다른사람의 소스를 복사하지 않고 직접 작성하였습니다.
#include<stdio.h>
#include<stdlib.h>
#include "1.h"

void main() {
	int ary2D[][3] = { {1,2,3},{4,5,6} };

	int r, c;
	int **ary = (int**)malloc(sizeof(int*) * 2);

	for (r = 0; r < 2; r++) {
		ary[r] = (int*)malloc(sizeof(int) * 3);
	}

	for (r = 0; r < 2; r++) {
		for (c = 0; c < 3; c++) {
			ary[r][c] = r + c;
		}
	}
	
	printf("sumAry2D_f1() %3d\n",sumAry2D_f1(ary2D,2,3));
	printf("sumAry2D_f2() %3d\n", sumAry2D_f2(ary2D, 2, 3));
	printf("sumAry2D_f3() %3d\n", sumAry2D_f3(ary2D, 2, 3));

	printf("sumAry2D_f4() %3d\n", sumAry2D_f4(ary, 2, 3));
	printf("sumAry2D_f5() %3d\n", sumAry2D_f5(&ary, 2, 3));
	
	
	freeAry2D(ary, 2);
	printf("ary FREE!\n");
}

void freeAry2D(int**ary, int n) {
	for (int i = 0; i < n; i++) {
		free(ary[i]);
	}
	free(ary);
}
int sumAry2D_f1(int ary2D[2][3], int n, int m) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum = sum + ary2D[i][j];
		}
	}
	return sum;
}
int sumAry2D_f2(int (*ary2D)[3], int n, int m) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum = sum + ary2D[i][j];
		}
	}
	return sum;
}
int sumAry2D_f3(int ary2D[][3], int n, int m) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum = sum + *(*(ary2D + i)+j);
		}
	}
	return sum;
}
int sumAry2D_f4(int **ary, int n, int m) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum = sum + *(*(ary + i) + j);
		}
	}
	return sum;
}
int sumAry2D_f5(int ***ary, int n, int m) {
	int sum = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum = sum + *(*(*ary+i)+j);
		}
	}
	return sum;
}
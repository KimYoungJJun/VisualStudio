#include<stdio.h>
#include<stdlib.h>
#include "2.h"
void main() {
	int ary3D[2][3][4] = { {{1,2,3,4} , {5,6,7,8}, {9,10,11,12}}, {{13,14,15,16}, {17,18,19,20}, {21,22,23,24}} };
	int r, c, d;
	int ***ary = (int***)malloc(sizeof(int**) * 2);
	for (r = 0; r < 2; r++) {
		ary[r] = (int**)malloc(sizeof(int*) * 3);
	}
	for (r = 0; r < 2; r++) {
		for (c = 0; c < 3; c++) {
			ary[r][c] = (int*)malloc(sizeof(int) * 4);
		}
	}
	for (r = 0; r < 2; r++) {
		for (c = 0; c < 3; c++) {
			for (d = 0; d < 4; d++) {
				ary[r][c][d] = r + c + d;
			}
		}
	}
	printf("sumAry3D_f1() %3d\n", sumAry3D_f1(ary3D, 2,3,4));
	printf("sumAry3D_f2() %3d\n", sumAry3D_f2(ary3D, 2,3,4));
	printf("sumAry3D_f3() %3d\n", sumAry3D_f3(ary3D, 2,3,4));

	printf("sumAry3D_f4() %3d\n", sumAry3D_f4(ary, 2,3,4));
	printf("sumAry3D_f5() %3d\n", sumAry3D_f5(&ary, 2,3,4));

	freeAry3D(ary, 2, 3);

	printf("ary FREE!\n");
}
int sumAry3D_f1(int ary3D[][3][4], int n, int m, int l) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < l; k++) {
				sum = sum + ary3D[i][j][k];
			}
		}
	}
	return sum;
}
int sumAry3D_f2(int ary3D[2][3][4], int n, int m,int l) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < l; k++) {
				sum = sum + ary3D[i][j][k];
			}
		}
	}
	return sum;
}
int sumAry3D_f3(int (*ary3D)[3][4], int n, int m,int l) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < l; k++) {
				sum = sum + ary3D[i][j][k];
			}
		}
	}
	return sum;
}
int sumAry3D_f4(int ***ary, int n, int m,int l) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < l; k++) {
				sum += *( *(*(ary+i)+j) +k);
			}
		}
	}
	return sum;
}
int sumAry3D_f5(int ****pary, int n, int m,int l) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < l; k++) {
				sum += *(*(*(*pary + i) + j));
			}
		}
	}
	return sum;
}
void freeAry3D(int ***ary,int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			free(ary[i][j]);
		}
		free(ary[i]);
	}
	free(ary);
}
#include<stdio.h>
int sumAry2D_f1(int ary2D[2][3], int n, int m);
int sumAry2D_f2(int(*ary2D)[3], int n, int m);
int sumAry2D_f3(int ary2D[][3], int n, int m);
int sumAry2D_f4(int **ary2D, int n, int m);
int sumAry2D_f5(int ***ary2D, int n, int m);
void freeAry2D(int **ary, int n);
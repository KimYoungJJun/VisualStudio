#include<stdio.h>
#include<stdlib.h>
int sumAry3D_f1(int ary3D[][3][4], int n, int m, int l);
int sumAry3D_f2(int ary3D[2][3][4], int n, int m, int l);
int sumAry3D_f3(int(*ary3D)[3][4], int n, int m, int l);
int sumAry3D_f4(int ***ary, int n, int m, int l);
int sumAry3D_f5(int ****pary, int n, int m, int l);
void freeAry3D(int ***ary, int n, int m);
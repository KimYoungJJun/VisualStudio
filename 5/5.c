#include<stdio.h>
#include<stdlib.h>
#define MAX_TERM 100

typedef struct {
	float coef;
	int expon;
}term;
term terms[MAX_TERM];

int avail = 0;
void attach(float coefficient, int exponent) {
	if (avail >= MAX_TERM) {
		fprintf(stderr, "Too many terms in the polynomial\n");
		exit(EXIT_FAILURE);
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}

int COMPARE(int x, int y) {
	if (x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}
void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD) {
	float coefficient;
	*startD = avail;
	while (startA <= finishA && startB <= finishB) {
		switch (COMPARE(terms[startA].expon, terms[startB].expon)) {
		case-1:
			attach(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		case 0:
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient) {
				attach(coefficient, terms[startA].expon);
			}
			startA++;
			startB++;
			break;
		case 1:
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
		}
		for (; startA <= finishA; startA++) {
			attach(terms[startA].coef, terms[startA].expon);
		}
		for (; startB <= finishB; startB++) {
			attach(terms[startB].coef, terms[startB].expon);
		}
		*finishD = avail - 1;
	}
}
void main() {
	int a, b;
	int coef, exp;
	printf("Input the number of items of A : ");
	scanf("%d",&a);

	printf("Input the number of items of B : ");
	scanf("%d", &b);

	printf("Input in descending order\n");
	
	for (int i = 1; i <= a; i++) {
		printf("%d번째 계수와 차수 입력 A(x), ex 10 3) : ", i);
		scanf("%d %d", &coef, &exp);
		attach(coef, exp);
	}
	for (int i = 1; i <= b; i++) {
		printf("%d번째 계수와 차수 입력 B(x), ex 10 3) : ", i);
		scanf("%d %d", &coef, &exp);
		attach(coef, exp);
	}

}
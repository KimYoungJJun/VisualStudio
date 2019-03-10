//2016114673 �迵��
//������ �� �ҽ������� �ٸ������ �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
#include<stdio.h>
#include<time.h>

int f(int  n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		return f(n - 1) + f(n - 2);
	}
}

void main() {
	int n, result = 0, step = 5;
	double duration;
	clock_t start;

	printf("     n     time\n");
	for (n = 5; n <= 40; n += step) {
		start = clock();

		result = f(n);

		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		printf("%6d     %f\n", n, duration);
	}
}
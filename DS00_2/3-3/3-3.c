//2016114673 �迵��
//������ �� �ҽ������� �ٸ������ �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
#include<stdio.h>
#include<time.h>
int fibo_tail(int fibo_num1, int fibo_num2, int n) {
	if (n == 1) {
		return fibo_num2;
	}
	else {
		return fibo_tail(fibo_num2, fibo_num1 + fibo_num2,n-1);
	}
}
void main() {
	int n, step = 5;
	clock_t start;
	double duration;
	int result = 0;

	printf("    n    time\n");
	for (n = 5; n <= 100; n+=step) {

		start = clock();
		result = fibo_tail(1, 1, n);
		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;

		printf("%6d    %f\n", n, duration);
	}
}
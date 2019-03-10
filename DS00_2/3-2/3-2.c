//2016114673 김영준
//본인은 이 소스파일을 다른사람의 소스를 복사하지 않고 직접 작성하였습니다.
#include<stdio.h>
#include<time.h>
void fibo_iter(int n) {
	int i, temp1 = 1, temp2 = 1, pre_temp1 = 0;

	for (i = 3; i <= n; i++) {
		pre_temp1 = temp1;
		temp1 = temp2;
		temp2 = temp2 + pre_temp1;
	}
}
void main() {
	int step = 5;
	double duration;
	clock_t start;
	int n;

	printf("    n    time\n");
	for (n = 0; n <= 100; n += step) {
		start = clock();
		fibo_iter(n);
		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;

		printf("%6d      %f\n", n, duration);
	}
}
//2016114673 김영준
//본인은 이 소스파일을 다른사람의 소스를 복사하지 않고 직접 작성하였습니다.
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
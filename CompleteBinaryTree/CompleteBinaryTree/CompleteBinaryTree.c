#include<stdio.h>
int odd(int n) {
	if (n <= 1) {
		return n;
	}
	else {
		return odd(n - 1) + odd(n - 1);
	}
}
void main() {
	int n;
	int result;
	scanf("%d", &n);
	result =odd(n);
	printf("%d\n", result);
}
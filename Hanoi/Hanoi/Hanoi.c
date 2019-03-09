#include<stdio.h>
void hanoi(int n, char from , char temp,char to) {
	if (n <= 1) {
		printf("원판 1을 %c에서 %c로 이동\n",from,to);
	}
	else {
		hanoi(n-1,from,to,temp);
		printf("원판 %d를 %c에서 %c로 이동\n", n, from, to);
		hanoi(n - 1, temp, from, to);
	}
}
void main()
{
	int n;
	char from = 'A';
	char temp = 'B';
	char to = 'C';
	printf("원판 개수를 입력하세요 : ");
	scanf("%d", &n);
	hanoi(n, from, temp, to);
}

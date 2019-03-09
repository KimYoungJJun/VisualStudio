#include<stdio.h>
void hanoi(int n, char from , char temp,char to) {
	if (n <= 1) {
		printf("���� 1�� %c���� %c�� �̵�\n",from,to);
	}
	else {
		hanoi(n-1,from,to,temp);
		printf("���� %d�� %c���� %c�� �̵�\n", n, from, to);
		hanoi(n - 1, temp, from, to);
	}
}
void main()
{
	int n;
	char from = 'A';
	char temp = 'B';
	char to = 'C';
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%d", &n);
	hanoi(n, from, temp, to);
}

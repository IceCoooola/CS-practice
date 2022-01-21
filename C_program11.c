#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int cal(int n)
{
	if (n > 0)
		return n * n + cal(n - 1);
	else
		return 0;
}

int main()
{
	int num;
	printf("Please enter a number.");
	scanf("%d", &num);
	printf("%d", cal(num));
	return 0;
}

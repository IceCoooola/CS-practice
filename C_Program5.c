#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void Input(int* a, int* b, int* c, int* d)
{
	printf("Please enter four integer values.>:");
	scanf("%d%d%d%d", *(&a), *(&b), *(&c), *(&d));
}
void Print(int a, int b, int c, int d)
{
	printf("\nThe four integer values are: %d %d %d %d\n\n", a, b, c, d);
}
int Largest_value(int a, int b, int c, int d)
{
	if (a > b && a > c && a > d)
	{
		return a;
	}
	else if (b > a && b > c && b > d)
	{
		return b;
	}
	else if (c > a && c > b && c > d)
	{
		return c;
	}
	else if (d > a && d > b && d > c)
	{
		return d;
	}
}
void compare(int* a, int* b, int* c, int* d)
{
	int t;
	if (*a < *b)
	{
		t = *a;
		*a = *b;
		*b = t;
	}
	if (*a < *c)
	{
		t = *a;
		*a = *c;
		*c = t;

	}
	if (*a < *d)
	{
		t = *a;
		*a = *d;
		*d = t;
	}
	if (*b < *c)
	{
		t = *b;
		*b = *c;
		*c = t;
	}
	if (*b < *d)
	{
		t = *b;
		*b = *d;
		*d = t;
	}
	if (*c < *d)
	{
		t = *c;
		*c = *d;
		*d = t;
	}
}


int main()
{
	int a, b, c, d;
	Input(&a, &b, &c,&d);
	Print(a,b,c,d);
	printf("The largest value is :%d\n\n",Largest_value(a, b, c, d));
	printf("The value will sort from high to low.\n\n");
	compare(&a, &b, &c, &d);
	Print(a, b, c, d);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void int_print(int arr[],int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
}

int float_print(float arr[],int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", arr[i]);
	}
}

int int_cmp(const void* e1, const void* e2)
{
	return (*(int*)e1) - (*(int*)e2);
}

int float_cmp(const void* e1, const void* e2)
{
	if (*(float*)e1 == *(float*)e2)
	{
		return 0;
	}
	else if (*(float*)e1 > *(float*)e2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void test1()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int_print(arr,sz);
	qsort(arr, sz, sizeof(arr[0]), int_cmp);
	printf("\n");
	int_print(arr, sz);
}


void test2()
{
	float arr1[] = { 7.7,6.6,4.4,2.2,1.1,5.5,3.3 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	float_print(arr1, sz);
	qsort(arr1, sz, sizeof(arr1[0]), float_cmp);
	printf("\n");
	float_print(arr1, sz);
}

struct stu
{
	int age;
	char name[20];
};

int struct_cmp_by_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

void test3()
{
	struct stu s[3] = { {20,"zhangsan"},{10,"lisi"},{50,"wangermazi"}};
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), struct_cmp_by_age);
}

int struct_cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}

void test4()
{
	struct stu s[3] = { {20,"zhangsan"},{10,"lisi"},{50,"wangermazi"} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), struct_cmp_by_name);
}

int main()
{
	test1();//用qsort sort一个整形数组
	test2();//用qsort sort一个float数组
	test3();//用qsort sort一个structure by age
	test4();//用qsort sort一个structure by name
	return 0;
}

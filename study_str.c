#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>



int main()
{
	char arr1[] = { 'a','b','c' };
	printf("%d\n", sizeof(arr1));//sizeof计算大小，这里存了三个字符，所以是3
	printf("%d\n",strlen(arr1));//strlen遇到\0才能停止计算，arr1里没有放\0，所以会一直找，找到\0才停止
	return 0;
}

//char* my_strcpy(char* dest, const char* source)
//{
//	assert(dest);
//	assert(source);
//	while (*source != '\0')
//	{
//		*dest = *source;
//		dest++;
//		source++;
//	}
//	*dest = '\0';
//	return *source;
//}

char* my_strcpy(char* dest, const char* source)
{
	assert(dest);
	assert(source);
	char* ret = dest;
	while (*dest++ = *source++)
	{
		;
	}
	return ret;
}

int main()
{
	//模拟实现strcpy
	char arr1[10] = "abcdefg";
	//char* arr1 = NULL;
	char arr2[10] = "what";
	printf("%s\n", arr1);
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}


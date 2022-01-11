#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

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


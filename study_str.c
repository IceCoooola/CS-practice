#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int main()
{
	//C语言规定标准
	//memcpy 只要处理 不重叠的内存拷贝就可以
	//memmove 处理重叠的内存的拷贝
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	memcpy(arr, arr+2, 24);
	int i = 0;
	for (i; i < 10; i++)
		printf("%d ",arr[i]);
	printf("\n\n");
	for (i = 0; i < 10; i++)
		arr[i] = i + 1;
	memmove(arr, arr + 2, 24);
	i = 0;
	for (i; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;

}


void* my_memcpy(void*, const void*, size_t);

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//my_memcpy(arr + 2, arr, 20);
	memcpy(arr + 2, arr, 20);
	int i = 0;
	for (i; i < 10; i++)
		printf("%d ",arr[i]);
	return 0;
}

void* my_memcpy(void* dest, const void* src, size_t sz)
{
	assert(dest&&src&&sz);
	void* temp = dest;
	while (sz--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return temp;
}


void* my_memcpy(void* dest, const void* src, size_t sz)
{
	void* tmp = dest;
	int i = 0;
	char* destt = (char*)dest;
	char*srcc = (char*)src;
	for (i = 0; i < sz; i++)
	{
		*destt = *srcc;
		destt++;
		srcc++;
	}
	return tmp;
}
int main()
{
	int arr1[] = { 1,2,3,4,5};
	int arr2[5];
	int i = 0;
	my_memcpy(arr2, arr1, sizeof(arr1));
	for(i = 0;i<5;i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}

struct S
{
	char name[20];
	int age;
};

int main()
{
	struct S arr1[] = { {"zhangsan",20},{"lisi",30}};
	struct S arr2[3];
	memcpy(arr2, arr1, sizeof(arr1));
	for (int i = 0; i < 2; i++)
	{
		printf("%s\n", arr2[i].name);
		printf("%d\n", arr2[i].age);
	}
	return 0;
}

int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = {0};
	int i = 0;
	memcpy(arr2, arr1, sizeof(arr1));//memcpy 第一个元素是要拷贝的地址，第二个是要拷贝的内容，第三个是要拷贝的内容总大小，大小是字节
	for (i = 0;i<5;i++)
	printf("%d ", arr2[i]);
	return 0;
}

char* my_strstr(const char* str, const char* sub)
{
	while (*str)
	{
		char* strr = str;
		char* subb = sub;
		while (*strr == *subb)
		{
			strr++;
			subb++;
			if (*subb == '\0')
				return str;
		}
		str++;
	}
	return NULL;
}


char* my_strstr(const char* str, const char* sub)
{
	assert(str && sub);
	if (!*sub)
		return (char*)str;
	char* s1;
	char* s2;
	char* cur = (char*)str;
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)sub;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return cur;
		cur++;
	}
	return NULL;
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abc";
	char* p = my_strstr(arr1, arr2);
	if (p != NULL)
		printf("%s\n", p);
	else
		printf("没有。\n");
	return 0;
}

char* my_strncat(char* front, char* back, int n)
{
	char* ret = front;
	while (*front++)
		;
	front--;
	while (n--)
		if (!(*front++ = *back++))//logical not, true only if the operand is 0.
			return ret;
	*front = '\0';
	return ret;

}

int main()
{
	char arr1[30] = "abcdefg";
	char arr2[] = "hi\0qwer";
	strncat(arr1, arr2, 5);
	my_strncat(arr1, arr2, 5);
	printf("%s", arr1);
	return 0;
}


char* my_strncpy(char* dest,const char* source, int n)
{
	int i = 0;
	char* ret = dest;
	for (i = 0; i < n; i++)
	{
		if (*source != '\0')
			*dest++ = *source++;
		else
			*dest++ = '\0';
	}
	return ret;
}

int main()
{
	char arr1[30] = "abcdefghijklmn";
	char arr2[] = "hello \0 world";
	printf("%s\n", arr1);
	//strncpy(arr1, arr2, 20);
	my_strncpy(arr1, arr2, 20);
	printf("%s\n", arr1);
	return 0;
}

//int my_strcmp(const char* e1,const char* e2)
//{
// assert(e1&&e2);
//	while (*e1&&*e2)
//	{
//		if (*e1 - *e2 != 0)
//			return *e1 - *e2;
//		else
//		{
//			e1++;
//			e2++;
//		}
//	}
//	if (*e1 - *e2 == 0)
//		return 0;
//	else
//		return *e1 - *e2;
//	
//}

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	if (*str1 > *str2)
		return 1;
	else
		return -1;
}

int main()
{
	//模拟实现strcmp
	char arr1[] = "abc";
	char arr2[] = "abcd";
	printf("%d\n",my_strcmp(arr1, arr2));
	printf("%d\n",strcmp(arr1, arr2));
	return 0;
}

char* my_strcat(char* dest, const char* source)
{
	assert(dest);
	assert(source);
	char* ret = dest;
	while (*dest!='\0')
	{
		dest++;
	}
	while (*dest++ = *source++)
	{
		;
	}
	return ret;
}

int main()
{
	//模拟实现strcat
	char arr1[20] = "hello";
	char arr2[] = "world";
	printf("%s\n", arr1);
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

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


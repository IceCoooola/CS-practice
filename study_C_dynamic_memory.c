#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

void GetMemory(char** p, int num)
{
	*p = (char*)malloc(num);
}
void test(void)
{
	char* str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);
	//存在内存泄漏
}
int main()
{
	test();
	return 0;
}

void GetMemory(char* p)//如果要改正确的话这里应该是指针char**p
{
	p = (char*)malloc(100);//这里把一个临时变量allocate内存，但没free，所以导致内存泄露
	//如果要改正确的话这里*p解引用**p找到*p
}
void Test(void)
{
	char* str = NULL;
	GetMemory(str);//如果要改正确的话这里传&str
	//这里是传值，所以getmemory收到的是一个临时拷贝，不改变str
	strcpy(str, "hello world");//这里strcpy赋值给空指针，造成程序崩溃
	printf(str);//不输出任何值因为程序崩了
	//如果要改正确的话这里要加一句free(str);释放内存
}

int main()
{
	Test();
	return 0;
}


void test()
{
	int* p = (int*)malloc(400);
	if (p != NULL)
		*p = 20;
	//err! 动态开辟的内存一定要释放，出了程序不会自销，然后如果这时候不释放找都找不到去哪儿释放
}
int main()
{
	test();
	while (1)
	{
		malloc(1);//err! 疯狂开辟不free会占用极大的内存会导致内存泄露
		sleep(1000);//1000毫秒= 1秒
	}
	return 0;
}

int main()
{
	int* p = (int*)malloc(20);
	if (p == NULL)
		return 0;
	else
	{
		*p = 20;
	}
	free(p);
	//....写了很多程序
	//只要手动把p置为空指针就不会被多次释放
	free(p);//err! 对同一块动态内存空间多次释放会导致程序崩溃
	//谁申请谁回收，谁开辟谁释放
	return 0;
}

int main()
{
	int* p = malloc(40);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
			*p++ = i;//err!这种写法是错误的，p指向的被改变了
	}
	free(p);//free会让程序崩溃，free只能free  p的初始地址。

	return 0;
}

int main()
{
	//int* p = malloc(4);
	//*(p + 4) = 5;//err, 动态内存开辟的空间越界访问程序会假死机
	//int i; 5;
	//int* p = &i;
	//*p = 10;
	//free(p);// err, p存在stack区不是heap，free的话程序会假死
	//int* p = malloc(10*INT_MAX);
	//assert(p);
	//*p = 10;//err，这种写法不可以，一定要判断一下p是不是空指针，因为很可能对空指针进行解引用。

	return 0;
}

int main()
{
	int* p = malloc(10 * sizeof(int));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else 
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
		}	
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p+i));
		}
		printf("\n");
	}
	//如果这时候o开辟的空间不够用，可以用realloc加大
	int* p2 = realloc(p, 20 * sizeof(int));//realloc调整这块空间大小到后面的bytes
	//realloc返回一个新的地址，有可能是之前的，有可能是新创建的
	//如果realloc后面有足够的空间追加，那就追加上然后返回p
	//realloc后面没有足够的空间追加，那就重新找一块区域给之前的搬过去，（之前的释放掉）然后返回新的地址
	//realloc开辟后要用新的指针接收，因为realloc可能内存不够开辟失败，开辟失败会返回NULL，如果返回原来的指针，之前那块就也丢了找不到了
	int i;
	if (p2 == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else 
	{
		p = NULL;
		for (i = 0; i < 20; i++)
		{
			printf("%d ", *(p2 + i));
		}
		printf("\n");
		for (i = 10; i < 20; i++)
		{
			*(p2 + i) = i;
		}
		for (i = 0; i < 20; i++)
		{
			printf("%d ", *(p2 + i));
		}
		printf("\n");
	}
	free(p2);
	p2 = NULL;
	return 0;
}


int main()
{
	int* p = calloc(10, sizeof(int));//calloc开辟（10个元素，每个元素的大小）个空间并且初始化为0
	//calloc的优点是初始化，malloc的优点是效率高
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	free(p);//free释放掉这个空间
	p = NULL;//然后再把p赋值为空指针，以防有人用p，就成了野指针
	return 0;
}

//int main()
//{
//
//	int* p = (int*)malloc(10 * sizeof(int));
//	int* p1 = (int*)malloc(10 * sizeof(int));
//	if (p1 == NULL)
//	{
//		//打印错误的原因的一个方式
//		printf("%s", strerror(errno));//errno存失败码，strerror把失败码翻译
//	}
//	else 
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p1 + i) = i;
//			printf("%d ", *p1 + i);
//		}
//		
//	}
//	free(p);
//	free(p1);
//	p = NULL;
//	p1 = NULL;
//	return 0;
//}

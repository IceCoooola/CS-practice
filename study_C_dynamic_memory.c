
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

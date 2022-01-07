#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (((b==2)+(a==3)==1)&&
							((b==2)+(e==4)==1)&&
							((c==1) + (d==2) == 1)&&
							((c==5) + (d==3) == 1)&&
							((e==4) + (a==1) == 1))

						{
							if (a * b * c * d * e == 120)
							{
								printf("a = %d, b = %d, c = %d, d = %d, e = %d", a, b, c, d, e);
								return 0;
							}
						}
					}
				}
			}
		}
	}
	
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						int sum = 0;
						if (b == 2 && a != 3)
							sum++;
						else if (b != 2 && a == 3)
							sum++;
						if (b == 2 && e != 4)
							sum++;
						else if (b != 2 && e == 4)
							sum++;
						if (c == 1 && d != 2)
							sum++;
						else if(c != 1 && d == 2)
							sum++;
						if (c == 5 && d != 3)
							sum++;
						else if(c != 5 && d == 3)
							sum++;
						if (e == 4 && a != 1)
							sum++;
						else if (e != 4 && a == 1)
							sum++;
						if (sum == 5&& a!=b && a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&c!=d&&c!=e&&d!=e)
							
						{
							printf("a = %d, b = %d, c = %d, d = %d, e = %d", a, b, c, d, e);
							return 0;
						}
					}
				}
			}
		}
	}
	

	//5位选手预测比赛结果  每位选手都说对了一半
	//A：B第二，A第三
	//B：B第二，E第四
	//C：C第一，D第二
	//D：C第五，D第三
	//E：E第四，A第一
	//abc  bac    bca   cba   cab   acb
	//abc  acb    bca   bac   cab   cba
	return 0;
}

int main()
{
	int arr[4] = {0,1,2,3};
	int i = 0;
	int murderer = 0;
	for (i = 0; i < 4; i++)
	{
		murderer = i;
		int sum = 0;
		if (murderer!=0)
			sum++;
		if (murderer == 2)
			sum++;
		if (murderer == 3)
			sum++;
		if (murderer != 3)
			sum++;
		if (sum == 3)
		{
			break;
		}
	}
	if (i == 0)
		printf("murderer is A\n");
	if (i == 1)
		printf("murderer is B\n");
	if (i == 2)
		printf("murderer is C\n");
	if (i == 3)
		printf("murderer is D\n");
	//找凶手，4人中其中1人说了假话
	//A说：不是我    B说：是C    C说：是D    D说：C在说假话
	//如果 说了真话 结果为1   说了假话 结果为0    3个人说真话 那就是对的
	return 0;
}


//int main()
//{
//	char killer = 'a';
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//		{
//			printf("killer = %c", killer);
//		}
//	}
//	return 0;
//}

int main()
{
	int i = 0;
	int n = 0;
	int arr[10][10] = { 0 };
	for (i = 0; i < 10; i++)
	{
			int j = 0;
			if (i == 0)
			{
				arr[i][j] = 1;
				printf("%d \n", arr[i][j]);
			}
			else
			{
				for (j = 0; j < 10; j++)
				{
					if (j == 0)
					{
						arr[i][j] = 1;
					}
					else
					{
						arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
					}
					if (i == j)
					{
						arr[i][j] = 1;
						printf("%d", arr[i][j]);
						printf("\n");
						break;
					}
					printf("%d ", arr[i][j]);
				}
			}
		
	}
	//1      
	//1 1         
	//1 2 1   
	//1 3 3 1      
	//1 4 6 4 1  
	//1 5 10 10 5 1
	//1 6 15 20 15 6 1
	return 0;
}


int main()
{
	char a[1000] = { 0 };
	int i = 0;
	printf("%d\n", strlen(a));
	//strlen遇\0终止。ascii的0就是\0，所以 为0
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	//-128  --> 127
	//00000001  -->  1
	//00000010  -->  2
	//....
	//01111111  -->127
	//10000000  -->翻译过来是 -128
	//10000001  --> -127 (内存存的是补码，反码是10000000，源码是11111111，首位符号位，所以是-127)
	//.....
	//11111111  --> -1 （反码是11111110，源码是10000001，首位符号位。翻译过来是-1)
	//00000000  --> 0 
	printf("%d\n", strlen(a));
	return 0;
}

int main()
{
	unsigned int a = 0x1234;
	unsigned char b = *(unsigned char*)&a;//大端存储电脑上是00 00 12 34，&a 的位置指向00，所以打印出来是0
	//小端存储电脑上是 34 12 00 00， &a指向位置34，打印出来是34，转换成10进制 3*16+4 = 48+4 = 52
	printf("%d", b);
	return 0;
}

odd_first(int arr[], int sz)
{
	int left = 0;
	int right = sz;
	while (right > left)
	{
		if (arr[left] % 2 == 0 && arr[right] % 2 == 1)
		{
			int t = arr[left];
			arr[left] = arr[right];
			arr[right] = t;
			
		}
		left++;
		right--;
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0])-1;
	odd_first(arr,sz);
	for (i = 0; i <= sz; i++)
		printf("%d ", arr[i]);
	return 0;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		int j = 0;
		for (j = 0; j < sz-1; j++)
		{
			if (arr[j] % 2 == 0 && arr[j + 1] % 2 == 1)
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	for(i=0;i<sz;i++)
	printf("%d ", arr[i]);
	return 0;
}
//const char* my_strcpy(char* dest,const char* source)
//{
//	int i = 0;
//	while (source[i]!='\0')
//	{
//		dest[i] = source[i];
//		i++;
//	}
//	dest[i] = '\0';
//}
//int main()
//{
//	//模拟实现my_strcpy
//	char arr[] = "abcdef";
//	char arr2[10] = "aaaaaa";
//	my_strcpy(arr2, arr);
//	printf("%s", arr2);
//}

//int my_strlen(char* arr)
//{
//	if (*arr != '\0')
//		return 1 + my_strlen(arr + 1);
//	else
//		return 0;
//}

int my_strlen(char* arr)
{
	int i = 0;
	while (*arr != '\0')
	{
		arr++;
		i++;
	}
	return i;
}


int main()
{
	char arr[] = "abcdefg";
	my_strlen(arr);
	printf("%d", my_strlen(arr));
	return 0;
}

//int main()
//{
//	int i = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hello.");
// //死循环是因为arr[12]被改成了0， arr[12] i变回了0
//	}
//	return 0;
//}

//int main()
//{
//	int money = 0;
//	int coke = 0;
//	int bottle = 0;
//	scanf("%d", &money);
//	coke = money / 1;
//	bottle = coke;
//	while (bottle>=2)
//	{
//		bottle -= 2;
//		coke += 1;
//		bottle += 1;
//	}
//	printf("%d", coke);
//	1元钱一瓶汽水，两个空瓶可以换一瓶，20块钱能买多少？
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int line = 0;
//	scanf("%d", &line);
//	for (i = 0; i < line; i++)
//	{
//		int j = 0;
//		for (j = 0; j < line-i-1; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < (2*i)+1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 0; i < line-1; i++)
//	{
//		int j = 0;
//		for (j = 0; j <=i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < (line-1-i)*2 - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
	//for (i = line-1; i >= 0; i--)
	//{
	//	int j = 0;
	//	for (j = 0; j < line-i; j++)
	//	{
	//		printf(" ");
	//	}
	//	for (j = 0; j < (2 * i) + 1; j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	
	
	//      *
	//     ***
	//    *****
	//   *******
	//  *********
	// ***********
	//*************
//
//}

//int main()
//{
//	int i = 0;
//	for (i = 1; i < 100000; i++)
//	{
//		int ret = i;
//		int n = 0;
//		while (ret)
//		{
//			n++;
//			ret /= 10;
//		}
//		ret = i;
//		int sum = 0;
//		while (ret)
//		{
//			sum += pow(ret % 10,n);
//			ret /= 10;
//		}
//		if (sum == i)
//			printf("%d ", i);
//	}
//	
//	return 0;
//}

//int cal(int i)
//{
//	if (i != 0)
//		return 1 + cal(i / 10);
//	else return 0;
//}
//
//int main()
//{
//	int i = 12345;
//	printf("%d", cal(i));
//	//求位数
//}

//int main()
//{
//	int i = 100;
//	for (i = 100; i < 1000; i++)
//	{
//		if (pow(i / 100, 3) + pow(i % 10, 3) + pow(((i - i % 10) / 10) % 10, 3) == i)
//			printf("%d ", i);
//	}
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int n = 0;
//	int sum = 0;
//	scanf("%d%d", &a, &n);
//	int i = 0;
//	int ret = 0;
//	//2 22 222 2222 22222
//	for (i = 0; i < n; i++)
//	{
//		ret = ret*10+a;
//		sum += ret;
//	}
//	printf("%d", sum);
//	return 0;
//}
//int calc(int a, int i)
//{
//	if (i > 0)
//		return pow(10, (i-1)) * a + calc(a, i - 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d%d", &a, &n);
//	int i = 0;
//	int c = 0;
//	for (i = 0; i < n; i++)
//	{
//		c += calc(a, i+1);
//	}
//	printf("%d", c);
//	return 0;
//}

//void rev(char* a)
//{
//	char* left = a;
//	char* right = a+ strlen(a)-1;
//	while(left<right)
//	{
//		char t = *left;
//		*left = *right;
//		*right = t;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[100];
//	gets_s(arr,100);
//	rev(arr);
//	printf("%s", arr);
//}

//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//	return 0;
//}

//int main()
//{
//	int arr[] = {1,2,3,4};
//	printf("%d ", sizeof(arr));
//	printf("%d ", sizeof(arr+0));
//	printf("%d ", sizeof(*arr));
//	printf("%d ", sizeof(arr+1));
//	printf("%d ", sizeof(arr[1]));
//	printf("%d ", sizeof(&arr));
//	printf("%d ", sizeof(*&arr));
//	printf("%d ", sizeof(&arr+1));
//	printf("%d ", sizeof(&arr[0]));
//	printf("%d ", sizeof(&arr[0]+1));
//	return 0;
//}

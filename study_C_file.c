#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("%s\n", __FILE__);//__FILE__是文件名（文件名 = 地址+名字+后缀）
	printf("%d\n", __LINE__);//__LINE__是第多少行
}

int main()
{
	double a[10] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9 };
	double b;
	size_t ret_val;
	FILE* f = fopen("d:\\test.dat", "wb");
	fwrite(a, sizeof(double), 10, f);
	fclose(f);
	f = fopen("d:\\test.dat", "rb");
	while ((ret_val = fread(&b, sizeof(double), 1, f)) >= 1)
		printf("%lf", b);
	if (ferror(f))
		printf("file reading error");
	else if (feof(f))
		printf("file reading end with an EOF.");
	fclose(f);
	f = NULL;
	return 0;
}


int main()
{
	char c = NULL;
	FILE* f = fopen("d:\\test.txt", "r");
	if (!f)
	{
		perror("Open file failed.");//直接打印这话加上 error
		return EXIT_FAILURE;//EXIT_FAILURE是个1
	}
		while ((c = fgetc(f)) != EOF)//fgetc判断是否为EOF，文件后面没东西了会有EOF
		putchar(c);
	printf("\n");
	if (ferror(f))//判断是否有error，有的话return真
		puts("I/O error when reading");
	else if (feof(f))//feof判断是否为EOF，如果是EOF返回真，如果不是返回假
		puts("End of file reached successfully");
	fclose(f);
	f = NULL;
	return 0;
}

int main()
{
	FILE* f = fopen("d:\\test2.txt", "r");
	if (!f)
	{
		perror("Open file test2.txt");
		//perror操作 =打印上面那句话加上: strerror(errno)
	}
	else
	{
		//操作文件
	}
	fclose(f);
	f = NULL;
	return 0;
}

struct s {
	char c;
	int i;
};

void InitStu(struct s* stu)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		(stu+i)->c = 'b';
		(stu + i)->i = i;
	}
}

int main()
{
	FILE* f = fopen("d:\\testb.dat", "wb");
	struct s stu[5] = {0};
	InitStu(&stu);
	printf("size of the structure is %d\n", sizeof(struct s));
	fwrite(stu, sizeof(struct s), 5, f);
	fclose(f);
	struct s s[5] = { 0 };
	f = fopen("d:\\testb.dat", "rb");
	int size = 0;
	size = fread(s, sizeof(struct s), 5, f);//fread returns how many elements has been readed
	printf("%d element has been read\n",size);
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%c\n", s[i].c);
		printf("%d\n", s[i].i);
	}
	return 0;
}

int main()
{
	FILE* f = fopen("d:\\test.txt", "r");
	int i = ftell(f);
	printf("f's location at %d character\n", i);
	char c = fgetc(f);
	printf("the first char is %c\n", c);
	i = ftell(f);
	printf("f's location at %d character\n", i);
	rewind(f);//relocate f pointer to the first character
	i = ftell(f);
	printf("after rewind, f's location at %d character\n", i);
	fclose(f);
	f = NULL;
	return 0;
}

int main()
{
	FILE* f = fopen("d:\\test.txt", "r");
	//test.txt 里面放了abcdefg
	fseek(f, -2, SEEK_END);
	//从最后开始数（这里指向g后面），倒数第二个字符
	char c = fgetc(f);
	printf("%c\n", c);
	int i = ftell(f);
	//ftell 告诉你现在f指针指哪儿去了
	printf("%d\n", i);
	fclose(f);
	f = NULL;
	return 0;

}

int main()
{
	FILE* f = fopen("d:\\test.txt", "w");
	fprintf(f,"abcdefg");
	fclose(f);
	f = NULL;
	f = fopen("d:\\test.txt", "r");
	fseek(f, 5, SEEK_SET);//move the pointer to the 6th element (下标从0开始)
	char c = fgetc(f);
	printf("%c\n", c);
	fclose(f);
	f = NULL;
	return 0;
}

int main()
{
	char name[20] = "Andrew";
	char str[5] = "is";
	char str1[100];
	int age = 28;
	sprintf(str1,"%s %s %d years old.",name,str,age);
	printf("%s", str1);

	return 0;
}


int main()
{
	char sentence[] = "Rudolph is 12 years old";
	char str[20];
	char ss[20];
	int i;

	sscanf(sentence, "%s %s %d", str,ss, &i);
	printf("%s\n", ss);
	printf("%s -> %d\n", str, i);

	return 0;
}


int main()
{
	FILE* f = fopen("d:\\test.txt", "w");
	fputc('a', f);
	fputc('b', f);
	fputc('c', f);
	fputc('d', f);
	fclose(f);
	f = fopen("d:\\test.txt", "a");
	fputc('e', f);
	fputc('f', f);
	fputc('g', f);
	f = fclose(f);
	f = fopen("d:\\test.txt", "r");
	char c = 0;
	c = fgetc(f);	
	printf("%c", c);
	
	return 0;
}

int main()
{
	FILE* f = fopen("d:\\test.txt", "w");
	fputc('a', f);
	fputc('b', f);
	fputc('c', f);
	fputc('d', f);
	fputc('e', f);
	fputc('f', f);
	fputc('g', f);
	fclose(f);
	f = fopen("d:\\test.txt", "r");
	char c1 = fgetc(f);
	char c2 = fgetc(f);
	char c3 = fgetc(f);
	char c4 = fgetc(f);
	char c5 = fgetc(f);
	char c6 = fgetc(f);
	fclose(f);
	printf("%c%c%c%c%c%c", c1, c2, c3, c4, c5, c6);
	return 0;
}
struct s {
	int a;
	char c;
	float f;
};

int main()
{
	struct s a = { 1,'c',3.14 };
	FILE* f = fopen("d:\\test.txt", "wb");
	fwrite(&a, sizeof(struct s), 1, f);
	fclose(f);
	f = fopen("d:\\test.txt", "rb");
	struct s x = { 0 };
	fread(&x, sizeof(struct s), 1, f);
	printf("%d, %c, %f\n", x.a, x.c, x.f);
	fclose(f);
	return 0;
}

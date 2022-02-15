#include<stdio.h>
#include<stdlib.h>

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

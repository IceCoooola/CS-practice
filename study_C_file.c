#include<stdio.h>
#include<stdlib.h>
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

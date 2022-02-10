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

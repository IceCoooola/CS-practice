#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROW 7
#define COL 20

void load(char name[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf("Please enter the name.>:");
		gets_s (name[i],col);
	}
}

void print(char name[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf("%s\n", name[i]);
	}
	printf("\n");
}

void sort(char name[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("\n\nThe names will sort in ascending order.\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			char temp[COL];
			if (strcmp(name[j], name[j + 1]) > 0)
			{
				strcpy(temp,name[j]);
				strcpy(name[j],name[j+1]);
				strcpy(name[j+1],temp);
			}
		}
	}
}

void search(char name[ROW][COL], int row, int col)
{
	int flag = 0;
	int i;
	char temp[COL];
	printf("Please enter the name you would like to search.>:");
	gets_s(temp,col);
	for (i = 0; i < row; i++)
	{
		if (strcmp(temp, name[i]) == 0)
		{
			flag = 1;
		}
	}	
	if (flag == 1)
	{
		printf("found.\n");
	}
	else
	{
		printf("not found.\n");
	}
}

int main()
{
	char name[ROW][COL];
	load(name, ROW, COL);
	printf("\n\nThe names are:\n");
	print(name, ROW, COL);
	sort(name, ROW, COL);
	print(name, ROW, COL);
	search(name, ROW, COL);
	return 0;
}

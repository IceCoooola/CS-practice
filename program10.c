#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5

struct Employee
{
	char name[20];
	char department[20];
	float current_income;
	float raise_percentage;
	float raise_amount;
	float newpay;
};

void load(struct Employee e[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("Please enter the name of the employee.>:");
		gets_s(e[i].name,20);
		printf("Please enter the department of the employee.>:");
		gets_s(e[i].department, 20);
		printf("Please enter the current yearly income of the employee.>:");
		scanf("%f", &e[i].current_income);
		printf("Please enter the raise percentage of the employee.>:");
		scanf("%f", &e[i].raise_percentage);
		getchar();
	}
}

void cal(struct Employee e[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		e[i].raise_amount = e[i].current_income * e[i].raise_percentage / 100;
		e[i].newpay = e[i].current_income + e[i].raise_amount;
	}
}

void sort(struct Employee e[], int size)
{
	int i;
	int j;
	struct Employee t;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (strcmp(e[j].name, e[j + 1].name) > 0)
			{
				t = e[j];
				e[j] = e[j + 1];
				e[j + 1] = t;
			}
		}
	}
}

void print(struct Employee e[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("The Employee's name is : %s\n", e[i].name);
		printf("The Employee's department is : %s\n", e[i].department);
		printf("The Employee's current income is : %0.2f\n", e[i].current_income);
		printf("The Employee's raise percentage is : %0.2f\n", e[i].raise_percentage);
		printf("The Employee's raise amount is : %0.2f\n", e[i].raise_amount);
		printf("The Employee's new pay amount is : %0.2f\n", e[i].newpay);
		printf("\n\n");
	}
}

void cal_ttl(struct Employee e[], int size)
{
	int i;
	double ttl_income = 0;
	double ttl_raise = 0;
	double ttl_newpay = 0;
	for (i = 0; i < size; i++)
	{
		ttl_income += e[i].current_income;
		ttl_raise += e[i].raise_amount;
		ttl_newpay += e[i].newpay;
	}
	printf("The total current yearly income is: %0.2lf\n", ttl_income);
	printf("The total raised amount is: %0.2lf\n", ttl_raise);
	printf("The total new pay amount is: %0.2lf\n", ttl_newpay);
	printf("\n\n");
}

void savetext(struct Employee e[], int size)
{
	FILE* f;
	f = fopen("d:\\program.txt", "w");
	int i;
	for (i = 0; i < size; i++)
	{
		fprintf(f,"%s\n", e[i].name);
		fprintf(f, "%s\n", e[i].department);
		fprintf(f, "%f\n", e[i].current_income);
		fprintf(f, "%f\n", e[i].raise_percentage);
		fprintf(f, "%f\n", e[i].raise_amount);
		fprintf(f, "%f\n", e[i].newpay);
	}
	fclose(f);
}

void retrievetext(struct Employee e[], int size)
{
	FILE* f;
	int len;
	f = fopen("d:\\program.txt", "r");
	int i;
	for (i = 0; i < size; i++)
	{
		fgets(e[i].name,sizeof(e[i].name),f);
		len = strlen(e[i].name);
		e[i].name[len - 1] = '\0';
		fgets(e[i].department, sizeof(e[i].department), f);
		len = strlen(e[i].department);
		e[i].department[len - 1] = '\0';
		fscanf(f,"%f\n", &e[i].current_income);
		fscanf(f, "%f\n", &e[i].raise_percentage);
		fscanf(f, "%f\n", &e[i].raise_amount);
		fscanf(f, "%f\n", &e[i].newpay);
	}
	fclose(f);
}

void savebin(struct Employee e[], int size)
{
	FILE* f;
	f = fopen("d:\\Employee.bin", "wb");
	fwrite(&e, sizeof(e[0]), size, f);
	fclose(f);
}

void retrievebin(struct Employee e[], int size)
{
	FILE* f;
	f = fopen("d:\\Employee.bin", "rb");
	fread(&e, sizeof(e[0]),size,f);
	fclose(f);
}

int main()
{
	struct Employee e[SIZE];
	load(e,SIZE);
	cal(e, SIZE);
	sort(e, SIZE);
	printf("\nEmployees are sorted in ascending order.\n\n");
	print(e, SIZE);
	cal_ttl(e,SIZE);

	savetext(e, SIZE);
	retrievetext(e, SIZE);
	printf("The text file has retrieved.\n");
	print(e, SIZE);

	savebin(e, SIZE);
	retrievebin(e, SIZE);
	printf("The binary file has retrieved.\n");
	print(e, SIZE);

	return 0;
}

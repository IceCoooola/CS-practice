#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void Input(char* name, char* department, float* currentincome)
{
	printf("Please enter the employee name.\n");
	gets_s(name, 20);
	printf("Please enter the employee's department.\n");
	gets_s(department, 20);
	printf("Please enter the employee's current income\n");
	scanf("%f", *(&currentincome));
}

void Cal(float currentincome, float* raisepercentage, double* raiseamount, double* newpay)
{
	if (currentincome <= 70000)
	{
		*raisepercentage = 8.6;
	}
	else if (currentincome <= 80000)
	{
		*raisepercentage = 7.4;
	}
	else if (currentincome <= 90000)
	{
		*raisepercentage = 5.8;
	}
	else if (currentincome > 90000)
	{
		*raisepercentage = 4.9;
	}
	*raiseamount = currentincome * (*raisepercentage) / 100;
	*newpay = currentincome + (*raiseamount);
}


void Print(char* name, char* department, float currentincome, float raisepercentage, float raiseamount, double newpay)
{
	printf("\nThe employee's name is %s\n", name);
	printf("The employee's department is %s\n", department);
	printf("The employee's current income is $%0.2f\n", currentincome);
	printf("The employee's raise percentage is %0.2f\n", raisepercentage);
	printf("The employee's raise amount is $%0.2f\n", raiseamount);
	printf("The employee's new pay amout is $%0.2f\n\n\n", newpay);
}

void Total(float currentincome, double raiseamount, double newpay, double* totalincome, double* totalraise, double* totalnewpay)
{
	*totalincome += currentincome;
	*totalraise += raiseamount;
	*totalnewpay += newpay;
}

void FinalPrint(double totalincome,double totalraise,double totalnewpay)
{

	printf("\nThe employee's total current income is $%0.2lf\n", totalincome);
	printf("The employee's total raise amount is %0.2lf\n", totalraise);
	printf("The employee's total new pay is %0.2lf\n", totalnewpay);
}
int main()
{

	float currentincome;
	float raisepercentage;
	char name[20];
	char department[20];

	double totalincome = 0;
	double totalraise = 0;
	double totalnewpay = 0;
	double raiseamount = 0;
	double newpay = 0;

	int i = 0;
	// I picked for loop because the loop is deterministic
	// The loop is entrance controlled
	for (i = 1; i <= 5; i++)
	{
		if (i > 1)
		{
			getchar();
		}
		Input(name, department, &currentincome, &raisepercentage);

		Cal(currentincome,&raisepercentage,&raiseamount,&newpay);

		Print(name, department, currentincome, raisepercentage, raiseamount, newpay);

		Total(currentincome, raiseamount, newpay, &totalincome, &totalraise, &totalnewpay);
	}

	FinalPrint(totalincome,totalraise,totalnewpay);

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

/*
This program finds the pay raises for employees.

Written by Di Bao

CS 36 11/01/2021
*/
void Input(char* name, char* department, float* currentincome)
{
	printf("Please enter the employee name.\n");
	gets_s(name, 20);
	printf("Please enter the employee's department.\n");
	gets_s(department, 20);
	printf("Please enter the employee's current income\n");
	scanf("%f", *(&currentincome));
}
float Calculate(currentincome)
{
	float raisepercentage = 0;
	if (currentincome <= 70000)
	{
		raisepercentage = 8.6;
	}
	else if (currentincome <= 80000)
	{
		raisepercentage = 7.4;
	}
	else if (currentincome <= 90000)
	{
		raisepercentage = 5.8;
	}
	else if (currentincome > 90000)
	{
		raisepercentage = 4.9;
	}
	return raisepercentage;
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

int main()
{

	float currentincome;
	float raisepercentage;
	char name[20];
	char department[20];

	double totalincome = 0;
	double totalraise = 0;
	double totalnewpay = 0;
	//employee1
	Input(name, department, &currentincome, &raisepercentage);

	raisepercentage = Calculate(currentincome);

	double raiseamount = currentincome * raisepercentage / 100;
	double newpay = currentincome + raiseamount;

	Print(name, department, currentincome, raisepercentage, raiseamount, newpay);

	totalincome += currentincome;
	totalraise += raiseamount;
	totalnewpay += newpay;

	//employee2
	getchar();
	
	Input(name, department, &currentincome, &raisepercentage);

	raisepercentage = Calculate(currentincome);

	raiseamount = currentincome * raisepercentage / 100;
	newpay = currentincome + raiseamount;

	Print(name, department, currentincome, raisepercentage, raiseamount, newpay);

	totalincome += currentincome;
	totalraise += raiseamount;
	totalnewpay += newpay;
	
	//employee3
	getchar();

	Input(name, department, &currentincome, &raisepercentage);

	raisepercentage = Calculate(currentincome);

	raiseamount = currentincome * raisepercentage / 100;
	newpay = currentincome + raiseamount;

	Print(name, department, currentincome, raisepercentage, raiseamount, newpay);

	totalincome += currentincome;
	totalraise += raiseamount;
	totalnewpay += newpay;

	//employee4
	getchar();

	Input(name, department, &currentincome, &raisepercentage);

	raisepercentage = Calculate(currentincome);

	raiseamount = currentincome * raisepercentage / 100;
	newpay = currentincome + raiseamount;

	Print(name, department, currentincome, raisepercentage, raiseamount, newpay);

	totalincome += currentincome;
	totalraise += raiseamount;
	totalnewpay += newpay;

	//employee5
	getchar();

	Input(name, department, &currentincome, &raisepercentage);

	raisepercentage = Calculate(currentincome);

	raiseamount = currentincome * raisepercentage / 100;
	newpay = currentincome + raiseamount;

	Print(name, department, currentincome, raisepercentage, raiseamount, newpay);

	totalincome += currentincome;
	totalraise += raiseamount;
	totalnewpay += newpay;


	printf("\nThe employee's total current income is $%0.2lf\n", totalincome);
	printf("The employee's total raise amount is %0.2f\n", totalraise);
	printf("The employee's total new pay is %0.2lf\n", totalnewpay);

}

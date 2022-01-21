#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void game()
{
	int num = rand() % 50 + 1;
	int guess = 0;
	int i = 0;
	printf("\n\nA random number generated!\n");
	printf("\n\nYou have six chance to guess the correct number!\n");
	printf("\nPlease guess the number from 1-50.\n");
	for (i = 1; i <= 6; i++)
	{
		printf("\nPlease enter your guess>:");
		scanf("%d", &guess);
		if (guess > num)
		{
			printf("\nYour guess is larger than the target!\n");
		}
		else if (guess < num)
		{
			printf("\nYour guess is smaller than the target!\n");
		}
		else
		{
			printf("\ncongradulations!\n");
			printf("\nYou took %d guesses to guess the number!\n\n",i);
			break;
		}
	}
	if (7 == i)
	{
		printf("\nYou lose.\n");
		printf("The correct number is: %d\n", num);
		printf("\nGAME OVER.\n\n\n");
	}
}
void menu()
{
	printf("*********************************\n");
	printf("**********Guess number***********\n");
	printf("*********************************\n");
	printf("*****1. play game    0. exit*****\n");
	printf("*********************************\n");
}
int main()
{
	time_t t;
	srand((unsigned int)time(&t));

	int input;
	do
	{
		menu();
		printf("Please choose>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("\nexit.");
			break;
		default:
			printf("invalid input.\n");
			break;
		}

	} 
	while (input);

	return 0;
}

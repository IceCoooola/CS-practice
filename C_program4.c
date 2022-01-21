#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>

void game()
{
	int r1;
	int r2;
	int r3;
	int r4;
	int bet;
	int guess1;
	int guess2;
	int guess3;
	int guess4;
	int correct = 0;
	r1 = rand() % 10;
	r2 = rand() % 10;
	r3 = rand() % 10;
	r4 = rand() % 10;
	printf("How much would you like to bet:>");
	scanf("%d", &bet);
	printf("please enter four number from 0-9.:>");
	scanf("%d%d%d%d", &guess1, &guess2, &guess3, &guess4);
	if (r1 == guess1)
	{
		correct += 1;
	}
	if (r2 == guess2)
	{
		correct += 1;
	}
	if (r3 == guess3)
	{
		correct += 1;
	}
	if (r4 == guess4)
	{
		correct += 1;
	}
	if (correct == 4)
			 {
		 		 printf("***************\n\n");
				 printf("4 unit matched!\n\n");
				 printf("***************\n\n");
				 printf("you win five times your bet!\n\n");
				 bet *= 6;
				 printf("now you have %d in your wallet.\n\n", bet);
				 printf("Play again?\n\n");
			 }
	else if (correct == 3)
	{
		printf("3 unit matched!\n\n");
		printf("you win two times your bet!\n\n");
		bet *= 3;
		printf("now you have %d in your wallet.\n\n", bet);
		printf("Play again?\n\n");
	}
	else if (correct == 2)
	{
		printf("2 unit matched!\n\n");
		printf("you win an amount equal to your bet!\n\n");
		bet *= 2;
		printf("now you have %d in your wallet.\n\n", bet);
		printf("Play again?\n\n");
	}
	else if (correct == 1)
	{
		printf("1 unit matched!\n\n");
		printf("you lose!\n\n");
		bet = 0;
		printf("now you have %d in your wallet.\n\n", bet);
		printf("Play again?\n\n");
	}
	else if (correct == 0)
	{
		printf("0 unit matched!\n\n");
		printf("you lose!\n\n");
		bet = 0;
		printf("now you have %d in your wallet.\n\n", bet);
		printf("Play again?\n\n");
	}


}


void menu()
{
	printf("*********************************\n");
	printf("*********Pick four game**********\n");
	printf("*********************************\n");
	printf("*****1. play game    0. exit*****\n");
	printf("*********************************\n");
	return menu;
}
int main()
{

	int input = 0;
	time_t t;
	srand((unsigned)time(&t));
	do {
		menu();
		printf("Please choose:>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit program.");
			break;
		default:
			break;
		}
	}
	while (input);
	return 0;
}

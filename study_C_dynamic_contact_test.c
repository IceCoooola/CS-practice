#include"dynamic_contact.h"
//简易版练习malloc relloc
void menu()
{
	printf("*************************\n");
	printf("******Contact List*******\n");
	printf("****1. Add     2. Del****\n");
	printf("****3. Show    0. Exit***\n");
	printf("*************************\n");

}

enum
{
	EXIT,
	ADD,
	DEL,
	SHOW,
};
int main()
{
	int input;
	Contact c;
	InitCon(&c);
	do 
	{
		menu();
		printf("Please choose:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			DestroyCon(&c);
			printf("Exiting Program.\n");
			break;
		case ADD:
			AddCon(&c);
			break;
		case DEL:
			DelCon(&c);
			break;
		case SHOW:
			ShowCon(&c);
			break;
		default:
			printf("invalid data! Please reenter:>");
			break;
		}
	}
	while (input);
	return 0;
}

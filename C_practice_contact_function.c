#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"

void Init(struct info* ps)
{
	memset(ps->people,0,sizeof(ps->people));
	ps->num = 0;
}

void AddName(struct info* p)
{
	//name, age, gender, tel, address
	printf("Please enter the name:>");
	scanf("%s", (p->people[p->num].name));
	printf("Please enter the age:>");
	scanf("%d", &(p->people[p->num].age));
	printf("Please enter the gender:>");
	scanf("%s", &(p->people[p->num].gender));
	printf("Please enter the telephone number:>");
	scanf("%s", &(p->people[p->num].tel));
	printf("Please enter the address:>");
	scanf("%s", &(p->people[p->num].address));
	(p->num)++;
}


void ShowContact(struct info* p)
{
	int i = 0;
	printf("%-15s\t%-6s\t%-6s\t%-13s\t%-20s\n","name","age","gender","telephone","address");
	for (i = 0; i < p->num; i++)
	{
		printf("%-15s\t%-6d\t%-6s\t%-13s\t%-20s\n",
			p->people[i].name,
			p->people[i].age,
			p->people[i].gender,
			p->people[i].tel, 
			p->people[i].address);
	}
}

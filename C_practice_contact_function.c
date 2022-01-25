#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"

int FindName(struct info* p, char name[MAX_NAME])
{
	int i;
	for (i = 0; i < p->num; i++)
	{
		if (strcmp(name, p->people[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

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
	scanf("%s", (p->people[p->num].gender));
	printf("Please enter the telephone number:>");
	scanf("%s", (p->people[p->num].tel));
	printf("Please enter the address:>");
	scanf("%s", (p->people[p->num].address));
	(p->num)++;
}

void SortName(struct info* p)
{
	int i;
	for (i = 0; i < p->num; i++)
	{
		int j = 0;
		for (j = 0; j < p->num - 1; j++)
		{
			if (strcmp(p->people[j].name, p->people[j + 1].name) > 0)
			{
				struct contact temp = p->people[j];
				p->people[j] = p->people[j + 1];
				p->people[j + 1] = temp;
			}
		}
	}

}

void DelName(struct info* p)
{
	char name[MAX_NAME];
	printf("Please enter the name of contact that you want to delete.:>");
	scanf("%s", name);
	int ret = FindName(p, name);
	if (ret == -1)
	{
		printf("Name no found.\n");
	}
	else
	{
		int i = 0;
		for (i = ret; i < p->num - 1; i++)
		{
			p->people[i] = p->people[i + 1];
		}
		p->num--;
		printf("Deleted.\n");
	}
}

void FindCon(struct info* p)
{
	char name[MAX_NAME];
	printf("Please enter the name of contact that you want to find.\n");
	scanf("%s", name);
	int ret = FindName(p, name);
	if (ret == -1)
	{
		printf("Contact no found.\n");
	}
	else
	{
		printf("%-15s\t%-6s\t%-6s\t%-13s\t%-20s\n", "name", "age", "gender", "telephone", "address");
		printf("%-15s\t%-6d\t%-6s\t%-13s\t%-20s\n",
			p->people[ret].name,
			p->people[ret].age,
			p->people[ret].gender,
			p->people[ret].tel,
			p->people[ret].address);
	}
}

void ModifyCon(struct info* p)
{
	char name[MAX_NAME];
	printf("Please enter the name of contact that you want to modify.\n");
	scanf("%s", name);
	int ret = FindName(p, name);
	if (ret == -1)
	{
		printf("Name no found.\n");
	}
	else
	{
		printf("Please enter the name:>");
		scanf("%s", (p->people[ret].name));
		printf("Please enter the age:>");
		scanf("%d", &(p->people[ret].age));
		printf("Please enter the gender:>");
		scanf("%s", (p->people[ret].gender));
		printf("Please enter the telephone number:>");
		scanf("%s", (p->people[ret].tel));
		printf("Please enter the address:>");
		scanf("%s", (p->people[ret].address));
	}
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

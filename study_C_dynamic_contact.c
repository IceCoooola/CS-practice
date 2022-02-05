#include"dynamic_contact.h"

CheckCapacity(Contact* c)
{
	if (c->used == c->capacity)
	{
		PeoInfo* tmp;
		tmp = (PeoInfo*)realloc(c->p, ((c->capacity + 2) * sizeof(PeoInfo)));
		if (tmp != NULL)
		{
			c->p = tmp;
			c->capacity += 2;
			printf("Added capacity.\n");
		}
	}
}

int FindName(Contact* c, char name[MAX_NAME])
{
	int i;
	for (i = 0; i < c->used; i++)
	{
		if (strcmp(name, c->p[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

InitCon(Contact* c)
{
	c->capacity = INIT_CAPACITY;
	c->used = 0;
	c->p = malloc(INIT_CAPACITY * sizeof(PeoInfo));
}

DestroyCon(Contact* c)
{
	free(c->p);
	c->p = NULL;
}

AddCon(Contact* c)
{
	//先check一下满了没，满了就加
	CheckCapacity(c);
	printf("Please enter the name:>");
	scanf("%s", (c->p[c->used].name));
	printf("Please enter the age:>");
	scanf("%d", &(c->p[c->used].age));
	printf("Please enter the gender:>");
	scanf("%s", (c->p[c->used].gender));
	printf("Please enter the telephone number:>");
	scanf("%s", (c->p[c->used].tel));
	printf("Please enter the address:>");
	scanf("%s", (c->p[c->used].address));
	(c->used)++;
}

DelCon(Contact* c)
{
	char name[MAX_NAME];
	printf("Please enter the name of contact that you want to delete.:>");
	scanf("%s", name);
	int ret = FindName(c, name);
	if (ret == -1)
	{
		printf("Name no found.\n");
	}
	else
	{
		int i = 0;
		for (i = ret; i < c->used - 1; i++)
		{
			c->p[i] = c->p[i + 1];
		}
		c->used--;
		printf("Deleted.\n");
	}
}


ShowCon(const Contact* c)
{
	int i = 0;
	printf("%-15s\t%-6s\t%-6s\t%-13s\t%-20s\n", "name", "age", "gender", "telephone", "address");
	for (i = 0; i < c->used; i++)
	{
		printf("%-15s\t%-6d\t%-6s\t%-13s\t%-20s\n",
			c->p[i].name,
			c->p[i].age,
			c->p[i].gender,
			c->p[i].tel,
			c->p[i].address);
	}
}

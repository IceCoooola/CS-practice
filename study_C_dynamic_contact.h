#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_NAME 20
#define MAX_GENDER 5
#define MAX_ADDRESS 20
#define MAX_TEL 12
#define INIT_CAPACITY 3

typedef struct PeoInfo {
	char name[MAX_NAME];
	char gender[MAX_GENDER];
	char tel[MAX_TEL];
	char address[MAX_ADDRESS];
	int age;
	//（名字，电话，性别，住址，年龄）
}PeoInfo;

typedef struct Contact {
	PeoInfo* p;
	int capacity;
	int used;
}Contact;

InitCon(Contact* c);

DestroyCon(Contact* c);

AddCon(Contact* c);

DelCon(Contact* c);

ShowCon(const Contact* c);

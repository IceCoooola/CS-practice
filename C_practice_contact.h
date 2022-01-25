#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 20
#define MAX_TEL 12
#define MAX_GENDER 7
#define MAX_ADDRESS 40
#define MAX 1000
struct contact {
	//（名字，电话，性别，住址，年龄）
	char name[MAX_NAME];
	int age;
	char gender[MAX_GENDER];
	char tel[MAX_TEL];
	char address[MAX_ADDRESS];
};

struct info {
	int num;//已经放进去的信息
	struct contact people[MAX];
};

void AddName(struct info* p);

void Init(struct info* p);

void ShowContact(struct info* p);

void DelName(struct info* p);

void FindCon(struct info* p);

void ModifyCon(struct info* p);

void SortName(struct info* p);

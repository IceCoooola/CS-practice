#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
// 1. test.c 测试
// 2. contact.c 实现函数的功能
// 3. contact.h 声明函数
// 
// 功能：
// 1. 存放 1000个好友的信息 （名字，电话，性别，住址，年龄）
// 2. 增加好友信息
// 3. 删除指定名字的好友信息
// 4. 查找好友信息
// 5. 修改好友信息
// 6. 打印好友信息
// 7. 排序
void menu() {
	printf("************************************\n");
	printf("********Your contact list***********\n");
	printf("*** 1.  Add  ******* 2. Delete *****\n");
	printf("*** 3. Find  ******* 4. Modify *****\n");
	printf("*** 5. Print ******* 0. Quit   *****\n");
	printf("************************************\n");
}
int main()
{

	int input = 0;
	do {
		menu();
		printf("Please choose>:");
		scanf("%d", &input);
	}
		while(input);
	return 0;
}

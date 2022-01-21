int check_sys1()
{
	int a = 1;
	return *(char*)&a;
}

int check_sys2()
{
	union Un
	{
		int i;
		char c;
		//共用体是共用一个空间
		//所以这个共用体的大小为最大的那个元素
	}u;
	u.i = 1;
	return u.c;
}

int main()
{
	//求大段存储还是小端存储
	if (check_sys1() == 1)
		printf("小端存储模式\n");
	else
		printf("大端存储模式\n");
	if (check_sys2() == 1)
		printf("小端存储模式\n");
	else
		printf("大端存储模式\n");

	return 0;
}

union Un
{
	char c;
	int i;
};

int main()
{
	//联合//共用体
	union Un u;
	printf("%d\n", sizeof(u));
	printf("%p\n", &u.i);
	printf("%p\n", &u.c);
	printf("%p\n", &u);

	return 0;
}


enum Color {
	red,
	green,
	blue
};

enum Sex {
	F,
	M,
	UNKNOW
};

int main()
{
	enum Color c = red;
	enum Sex s = F;
	//枚举
	return 0;
}


struct stu {
	int a : 2;//位段的成员都是同类型
	int b : 5;//位段的大小是bit（8个bit是一个字节）
	int c : 10;//位段的大小是按照成员大小去开发的
	int d : 30;//首先开一个int字节的空间，按成员往里面放，如果放不下了，浪费掉剩下的空间
};//然后再开辟一个int的空间，继续放。

struct stu2 {
	int a : 30;
	int b : 5;
	int c : 15;
	int d : 8;
	int e : 30;
};
struct stu3 {
	int a : 30;
	int b : 5;
	int c : 15;
	int d : 8;
	int e : 30;
	int f : 15;
};

struct stu4 {
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};

int main()
{
	printf("%d\n", sizeof(struct stu));
	printf("%d\n", sizeof(struct stu2));
	printf("%d\n", sizeof(struct stu3));
	printf("%d\n", sizeof(struct stu4));
	
	struct stu4 s = { 0 };
	s.a = 10;//1010
	s.b = 20;//10100
	s.c = 3;//11
	s.d = 4;//100
	printf("%d\n", s.a);
	printf("%d\n", s.b);
	printf("%d\n", s.c);
	printf("%d\n", s.d);
	return 0;
}


typedef struct stu {
	char a;
	int b;
	char c;
}S;

typedef struct stu2 {
	char a;
	char b;
	int c;
}S2;

typedef struct stu3 {
	int c;
	char a;
	char b;
}S3;

typedef struct stu4 {
	int a;
	char b;
	double c;
	char d;
}S4;

int main()
{
	printf("%d\n", sizeof(S));//结构体对其规则
	printf("%d\n", sizeof(S2));//第一个成员放在结构体变量偏移量为0的地址处
	printf("%d\n", sizeof(S3));//其他成员变量要对齐到（对齐数）的整倍地址处
	printf("%d\n", sizeof(double));//对齐数：编译器默认的一个对齐数与该成员大小的较小值 ，VS默认8
	printf("%d\n", sizeof(S4));//结构体总大小为最大对齐数的整倍数。
	return 0;
}

struct T
{
	double q;
	long w;
};

struct S
{
	char a;
	int b;
	struct T c;
	char d[10];
};

int main()
{
	struct S s = { 'a',5,{333.333,123456},"hello" };
	printf("%c, %d, %lf, %d, %s", s.a, s.b, s.c.q, s.c.w, s.d);
	return 0;
}

struct S
{
	int a;
	struct S* pS;
};//结构体的自引用

struct//不写结构体名字的是匿名结构体变量
{
	char name[20];
	int age;
	char describe[50];
}sa;//匿名结构体变量只能在这儿创建变量名

struct Stu
{
	char name[20];
	int age;
	char tel[11];
	char gender[2];
}a,b,c;//在这里创建的是全局变量

struct Stu q[5];//在这里创建的也是全局变量

int main()
{
	struct Stu s[5];//在这里创建的是局部变量
	return 0;
}

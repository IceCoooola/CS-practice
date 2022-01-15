
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


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

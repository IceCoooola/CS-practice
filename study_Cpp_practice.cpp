//如何继承析构器？


#include<iostream>

class Animal {
public:
	Animal(std::string name);
	~Animal();
	virtual void play() = 0;
private:
	std::string name;
};

Animal::Animal(std::string name)
{
	this->name = name;
	std::cout << name << " has born.\n";
}
Animal::~Animal()
{
	std::cout << name << " has dead.\n";
}
class Pig:public Animal 
{
public:
	Pig(std::string name);
	void play();
};

Pig::Pig(std::string name):Animal(name)
{

}

void Pig::play()
{
	std::cout << "Pig is playing.\n";
}


class Bird :public Animal
{
public:
	Bird(std::string name);
	~Bird();
	void play();
};

Bird::Bird(std::string name) :Animal(name)
{

}

void Bird::play()
{
	std::cout << "bird flying!\n";
}

int main()
{
	Animal* pig = new Pig("peiqi");
	pig->play();
	{
		Animal* pig2 = new Pig("peiqima");
		pig2->play();
	}
	Animal* bird = new Bird("QWQ");
	bird->play();

	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Rational 
{
public:
	Rational();
	Rational(int, int);
	~Rational();
	void rationalPrint();
	friend Rational operator+(Rational&, Rational&);
	friend Rational operator-(Rational&, Rational&);
	Rational operator*(Rational&);
	Rational operator/(Rational&);
private:
	int num;
	int dem;
};

Rational::Rational()
{
	num = 1;
	dem = 1;
}

Rational::~Rational()
{
	//std::cout << "Deleted.\n";
}

Rational::Rational(int x, int y)
{
	num = x;
	dem = y;
}

Rational operator+(Rational& x, Rational& y)
{
	Rational t;
	t.dem = x.dem * y.dem;
	t.num = x.num * y.dem + y.num * x.dem;
	return t;
}

Rational operator-(Rational& x, Rational& y)
{
	Rational t;
	t.dem = x.dem * y.dem;
	t.num = x.num * y.dem - y.num * x.dem;
	return t;
}

Rational Rational::operator*(Rational& x)
{
	return Rational(num * x.num, dem * x.dem);
}
Rational Rational::operator/(Rational& x)
{
	return Rational(num * x.dem, dem * x.num);
}

void Rational::rationalPrint()
{
	if (dem > num)
	{
		std::cout << num << "\n" << "--\n" << dem << std::endl<<std::endl;
	}
	else
	{
		if (num % dem == 0)
		{
			std::cout << num / dem<<"\n" << std::endl;
		}
		else
		{
			std::cout << num << "\n" << "--\n" << dem << std::endl << std::endl;
		}
	}
}
int main()
{
	Rational x(4, 4), y(3,5), z;
	x.rationalPrint();
	y.rationalPrint();
	z = x + y;
	z.rationalPrint();
	z = x - y;
	z.rationalPrint();
	z = x * y;
	z.rationalPrint();
	z = x / y;
	z.rationalPrint();
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
/*using namespace std;*/

class Complex {
public:
	Complex();
	Complex(int, int);
	~Complex();
	void complexPrint();
	Complex operator+(Complex& x);
	Complex operator-(Complex& x);
	Complex operator*(Complex& x);
	Complex operator/(Complex& x);
private:
	int real;
	int img;
};

Complex Complex::operator+(Complex& x)
{
	return Complex(real + x.real, img + x.img);
}

Complex Complex::operator-(Complex& x)
{
	return Complex(real - x.real, img - x.img);
}

Complex Complex::operator*(Complex& x)
{
	return Complex(real * x.real, img * x.img);
}

Complex Complex::operator/(Complex& x)
{
	return Complex(real / x.real, img / x.img);
}

Complex::Complex(int x, int y)
{
	real = x;
	img = y;
	std::cout << "created.2\n";
}

Complex::Complex()
{
	real = 0;
	img = 0;
	std::cout << "created.1\n";
}

Complex::~Complex()
{
	std::cout << "deleted" << std::endl;
}


void Complex::complexPrint()
{
	std::cout << "real part: " << real << std::endl;
	std::cout << "imaginary part: " << img << std::endl;
}
int main()
{
	Complex x(2, 2), y(10, 5), z;
	z = x + y;
	z.complexPrint();
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
/*using namespace std;*/

class Complex {
public:
	Complex();
	Complex(int, int);
	~Complex();
	Complex complexAdd(Complex& x);
	void complexPrint();
private:
	int real;
	int img;
};

Complex::Complex(int x, int y)
{
	real = x;
	img = y;
	std::cout << "created.2\n";
}

Complex::Complex()
{
	real = 0;
	img = 0;
	std::cout << "created.1\n";
}

Complex::~Complex()
{
	std::cout<<"deleted"<<std::endl;
}

Complex Complex::complexAdd(Complex& x)
{
	return Complex(real + x.real, img + x.img);
}

void Complex::complexPrint()
{
	std::cout << "real part: " << real << std::endl;
	std::cout << "imaginary part: " << img << std::endl;
}
int main()
{
	Complex x(2,2), y(10, 5), z;
	z = x.complexAdd(y);
	z.complexPrint();
	return 0;
}

#include<iostream>
#include<iomanip>
class Student {
public:
	Student(int = 0, int = 0, int = 0);
	~Student();
	void setData(int, int, int);
	void printData();
private:
	int test1, test2, test3;
};

Student::Student(int a, int b, int c)
{
	setData(a,b,c);
}
Student::~Student()
{
	std::cout << std::setw(10) << test1 << std::setw(10) << test2;
	std::cout << std::setw(10) << test3 << "destroyed" << std::endl;
}

void Student::setData(int a, int b, int c)
{
	test1 = a;
	test2 = b;
	test3 = c;
}

void Student::printData()
{
	std::cout << "|----------|----------|----------|" << std::endl;
	std::cout << "|" << std::setw(10) << "TEST1" << "|" << std::setw(10) << "TEST2"<<"|" << std::setw(10) << "TEST3" << "|" << std::endl;
	std::cout << "|" << std::setw(10) << test1 << "|" << std::setw(10) << test2<<"|" << std::setw(10) << test3 << "|" << std::endl;
	std::cout << "|----------|----------|----------|" << std::endl;
}

int main()
{
	Student one, two(50), three(50, 70), four(50, 70, 90);
	std::cout << "studnet one data:\n";
	one.printData();
	{
		std::cout << "studnet two data:\n";
		two.printData();
		std::cout << "studnet three data:\n";
		three.printData();
	}
	std::cout << "studnet four data:\n";
	four.printData();
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	int sum = 0;
	char t = '0';
	// cin >> t;
	//while ()
	//{
	//	cin >> t;
	//	sum += t;
	//}
	do 
	{
		sum += (int)t;
		cin >> t;
	} 
	while (t != '\n');
	
	/*while(cin.peek() != '\n')
	{
		cin >> t;
		sum += t;
	}*/
	cout << sum << endl;
	return 0;
}
//class Student {
//public:
//	Student();
//	~Student();
//	void setData(int a, int b ,int c);
//	void printData();
//private:
//	int test1, test2, test3;
//};
//
//Student::Student()
//{
//	test1 = test2 = test3 = 0;
//}
//
//Student::~Student()
//{
//	std::cout << "Student destructed." << std::endl;
//}
//
//void Student::setData(int a, int b, int c)
//{
//	test1 = a;
//	test2 = b;
//	test3 = c;
//}
//
//void Student::printData()
//{
//	std::cout << "\n";
//	std::cout << "Test 1: " << test1 << "\n";
//	std::cout << "Test 2: " << test2 << "\n";
//	std::cout << "Test 3: " << test3 << "\n";
//}
//
//int main()
//{
//	Student s1, s2;
//	s1.printData();
//	s2.setData(12, 13, 16);
//	s2.printData();
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>

class Person {
public:
	Person();
	void getSales();
	void printSales();
	static int MAX;
private:
	float totalSales();
	float sales[5];
};

int Person::MAX = 5;

Person::Person()
{
	int i = 0;
	for (i; i < MAX; i++)
		sales[i] = 0;
}

void Person::getSales()
{
	for (int i = 0; i < MAX; i++)
	{
		std::cout << "enter the amount for month " << i+1 << " :>";
		std::cin >> sales[i];
	}
}

float Person::totalSales()
{
	float sum = 0;
	for (int i = 0; i < MAX; i++)
		sum += sales[i];
	return sum;
}

void Person::printSales()
{
	std::cout << std::endl;
	std::cout << std::setprecision(2) << std::fixed << std::showpoint;
	for (int i = 0; i < MAX; i++)
	{
		std::cout << "Month " << i+1 << " : $" << sales[i] << std::endl;
	}
	std::cout << "TTL: " << totalSales() << std::endl;
}

int main()
{
	Person p;
	p.getSales();
	p.printSales();
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Super {
public:
	virtual void show();
};

void Super::show()
{
	std::cout << "Super\n";
}

class Sub :public Super {
public:
	void shower();
};

void Sub::shower() {
	std::cout << "Sub\n";
}

struct X {
	int a;
	int b;
};

struct andrew {

};

int main()
{
	Super* s = new Sub;
	Sub x;
	struct X p2;
	x.show();
	s->show();
	return 0;
}
#include"Header.h"

int main()
{
	Student one, two;
	one.printData();
	two.setData();
	two.printData();
	return 0;
}


//header file
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Student {
public:
	Student();
	void setData();
	void printData();
private:
	int test1;
	int test2;
	int test3;
	float avg;
};

Student::Student()
{
	test1 = 1;
	test2 = 1;
	test3 = 1;
	avg = 1;
}

void Student::printData()
{
	std::cout << "Test 1: " << test1<<"\n";
	std::cout << "Test 2: " << test2<<"\n";
	std::cout << "Test 3: " << test3<<"\n";
	std::cout << "avg: " << avg<<"\n";
}

void Student::setData()
{
	int x, y, z;
	std::cout << "enter test1:>";
	std::cin >> x;
	std::cout << "enter test2:>";
	std::cin >> y;
	std::cout << "enter test3:>";
	std::cin >> z;
	test1 = x;
	test2 = y;
	test3 = z;
	avg = (x + y + z) / (float)3;
}


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Student {
public:
	Student(); //default constructor
	void setData(int, int, int);
	void printData();
private:
	int test1, test2, test3;
	float avg;
};

Student::Student()
{
	test1 = test2 = test3 = 1;
	avg = (test1 + test2 + test3) / (float)3;
}

void Student::setData(int a, int b, int c)
{
	test1 = a;
	test2 = b;
	test3 = c;
	avg = (test1 + test2 + test3) / (float)3;
}

void Student::printData()
{
	std::cout << "Test 1: " << test1 << "\n";
	std::cout << "Test 2: " << test2 << "\n";
	std::cout << "Test 3: " << test3 << "\n";
	std::cout << "Average: " << avg << "\n";
}

int main()
{
	Student s1;
	s1.setData(11, 21, 31);
	s1.printData();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Student {
public:
	Student(); //default constructor
	void setData(int, int, int);
	void printData();
private:
	int test1, test2, test3;
	float avg;
};

Student::Student()
{
	test1 = test2 = test3 = 1;
	avg = (test1 + test2 + test3) / (float)3;
}

void Student::setData(int a, int b, int c)
{
	test1 = a;
	test2 = b;
	test3 = c;
	avg = (test1 + test2 + test3) / (float)3;
}

void Student::printData()
{
	std::cout << "Test 1: " << test1 << "\n";
	std::cout << "Test 2: " << test2 << "\n";
	std::cout << "Test 3: " << test3 << "\n";
	std::cout << "Average: " << avg << "\n";
}

int main()
{
	Student s1;
	s1.setData(11, 21, 31);
	s1.printData();
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Student {
public:
	char name[20];
	int test1, test2, test3;
	float avg;
};

int main()
{
	std::cout << "enter the name" << std::endl;
	Student s;
	std::cin.getline(s.name, 20);
	std::cout << "enter three test result." << std::endl;
	std::cin >> s.test1 >> s.test2 >> s.test3;
	s.avg = (s.test1 + s.test2 + s.test3) / (float)3;
	std::cout << "name: " << s.name;
	std::cout << "test 1: " << s.test1 << " test 2: " << s.test2 << " test 3: " << s.test3 << std::endl;
	std::cout << "avg: " << s.avg;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Class {
public:
	int a;
	static int b;
	char c;
	Class(int x, char y);
	void Print();
	const void Print1();
	//因为每个类都会传进来对象的地址，所以其实函数运行是this->属性（变量） 这么运行的
	// 所以静态属性存的是不一样的地方！！！
	// 在使用静态属性的时候，千万不要忘记分配内存！！（像声明一个变量一样声明一下她）
};

int Class::b = 10;
//正确的声明静态属性的方法↑
//坚持使用 : ClassName::MethodName();声明静态属性
//不要使用 ：ObjectName.MethodName() 因为会引起混乱，容易让人觉得不是静态属性
Class::Class(int x, char y)
{
	a = x;
	c = y;
}

void Class::Print()
{
	std::cout << "a = " << a<<std::endl;
}

const void Class::Print1()
{
	std::cout << "b = " << b << std::endl;
}

int main()
{
	Class C1(5,'c');
	C1.Print();
	C1.Print1();

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Point 
{
private:
	int x, y;
public:
	Point(int a, int b)
	{
		x = a;
		y = b;
	}
	void MovePoint(int a, int b)
	{
		x = a;
		y = b;
	}
	void Print()
	{
		std::cout << "x = " << x << ", y = " << y << std::endl;
	}
};

int main()
{
	Point point1(10, 10);
	point1.MovePoint(2, 2);
	point1.Print();
	return 0;
	//	//当point1调用MovePoint函数的时候，即将point1对象的地址传给了this指针。
//	//MovePoint函数的原型事实上应该是void MovePoint(Point* this, int a, int b)
//	//第一个参数是指向该类对象的一个指针，我们在定义成员函数的时候没看见是因为这个参数在类(class)中是隐含的
//	//这样point1的地址传给了this，所以在MovePoint函数中便可以显示的写成：
//	//void MovePoint(int a, int b) 
//	//{ this->x = a; this->y = b;}
//	//既可以知道，point1调用该函数后，也就是point1的数据成员被调用并更新了值。

}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

class Super
{
public:
	Super();
	~Super();
	static int Get_Count();
private:
	static int count;

};

int Super::count = 0;

Super::Super()
{
	count++;
	std::cout << "+1\n";
}

Super::~Super()
{
	count--;
	std::cout << "-1\n";
}

int Super::Get_Count()
{
	return count;
}

class Sub :public Super
{
	public:
		Sub();
};

Sub::Sub() : Super()
{
	;
}

int main()
{
	Sub S1;
	std::cout << "TTL:"<<Super::Get_Count() << std::endl;
	Sub S2;
	std::cout << "TTL:" << Super::Get_Count()<<std::endl;
	Sub S3;
	std::cout << "TTL:" << Super::Get_Count() << std::endl;
	return 0;
}
#include<iomanip>
using namespace std;


class Animal 
{
public:
	std::string name;
	Animal(std::string name);
	void eat();
	void sleep();
protected:
	void die();
private:
	void rebirth();
};

Animal::Animal(std::string input)
{
	name = input;
}

void Animal::eat()
{
	std::cout << "Eating.\n";
}

void Animal::sleep()
{
	std::cout << "Sleeping.\n";
}

void Animal::die() 
{
	std::cout << "dying.\n";
}

void Animal::rebirth()
{
	std::cout << "alive again.\n";
}

class Cat :public Animal
{
public:
	Cat(std::string name);
	void Die();
	void eat();
};

void Cat::Die()
{
	die();
	//rebirth();
}

Cat::Cat(std::string input): Animal(input)
{

}

void Cat::eat()
{
	std::cout<<"Cat is eating.\n";
}

class Dog :public Animal
{
public:
	Dog(std::string name);
	void eat();
};

void Dog::eat()
{
	Animal::eat();
	std::cout << "dog is eating.\n";
}

Dog::Dog(std::string input) :Animal(input)
{

}

int main()
{
	Cat cat("lucky");
	Dog dog("mochi");
	std::cout << cat.name<<std::endl;
	std::cout << dog.name<<std::endl;
	dog.name = "mochi";
	std::cout << cat.name << std::endl;
	cat.Die();
	cat.eat();
	dog.eat();
	return 0;
}
class Animal {
public:
	std::string name;
	int satiety;
	int fatigue;
	int happiness;
	Animal();
	void eat();
	void sleep();
	void play();
};

Animal::Animal()
{
	satiety = 5;
	fatigue = 5;
	happiness = 0;
}

void Animal::eat() 
{
	std::cout << name << " is eating.\n";
	satiety++;
}

void Animal::sleep()
{
	std::cout << name << " is sleeping.\n";
	fatigue-=3;
	satiety -= 3;
}

void Animal::play()
{
	std::cout << name << " is playing.\n";
	fatigue++;
	satiety--;
	happiness++;
}

class Cat : public Animal
{
public:
	void climb();
};

void Cat::climb()
{
	std::cout << name << " is climbing\n";
	fatigue++;
	happiness++;
	satiety--;
}

class Dog : public Animal 
{
public:
	void run();
};

void Dog::run()
{
	std::cout << name << " is running\n";
	fatigue++;
	happiness++;
	satiety--;
}

void menu()
{
	std::cout << "***************************\n";
	std::cout << "***1. dog        2. cat****\n";
	std::cout << "***0. quit       **********\n";
}

void catlist()
{
	std::cout << "***************************\n";
	std::cout << "***1. eat        2. sleep**\n";
	std::cout << "***3. play       4. climb**\n";
	std::cout << "***0. quit       **********\n";
}

void doglist()
{
	std::cout << "***************************\n";
	std::cout << "***1. eat        2. sleep**\n";
	std::cout << "***3. play       4. run  **\n";
	std::cout << "***0. quit       **********\n";
}

enum CD{
	DOG = 1,
	CAT
};

enum LIST {
	QUIT,
	EAT,
	SLEEP,
	PLAY,
	RUN
};

template <class T>
void show(T x)
{
	std::cout << "--------------------" << std::endl;
	std::cout << x.name << std::endl;
	std::cout <<setw(10)<<left<<"fatigue: " << x.fatigue << setw(10) << right << std::endl;
	std::cout << setw(10) << left << "happiness: " << x.happiness << setw(10) << right << std::endl;
	std::cout << setw(10) << left << "satiety: " << x.satiety << setw(10) << right << std::endl;
}

int main()
{
	Cat cat;
	Dog dog;
	cat.name = "Lucky";
	dog.name = "Mochi";
	menu();
	int input;
	int choice;
	std::cin >> input;
	while (input)
	{
		switch (input)
		{
		case DOG:
			doglist();
			std::cin >> choice;
			switch (choice)
			{
			case EAT:
				dog.eat();
				break;
			case SLEEP:
				dog.sleep();
				break;
			case PLAY:
				dog.play();
				break;
			case RUN:
				dog.run();
				break;
			}
			break;
		case CAT:
			catlist();
			std::cin >> choice;
			switch (choice)
			{
			case EAT:
				cat.eat();
				break;
			case SLEEP:
				cat.sleep();
				break;
			case PLAY:
				cat.play();
				break;
			case RUN:
				cat.climb();
				break;
			}
			break;
		default:
			break;
		}
		show(cat);
		show(dog);
		menu();
		cin >> input;
	}


	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

class Animal {
public:
	std::string name;
	int satiety;
	int fatigue;
	int happiness;
	Animal();
	void eat();
	void sleep();
	void play();
};

Animal::Animal()
{
	satiety = 5;
	fatigue = 5;
	happiness = 0;
}

void Animal::eat() 
{
	std::cout << name << " is eating.\n";
	satiety++;
}

void Animal::sleep()
{
	std::cout << name << " is sleeping.\n";
	fatigue-=3;
	satiety -= 3;
}

void Animal::play()
{
	std::cout << name << " is playing.\n";
	fatigue++;
	satiety--;
	happiness++;
}

class Cat : public Animal
{
public:
	void climb();
};

void Cat::climb()
{
	std::cout << name << " is climbing\n";
	fatigue++;
	happiness++;
	satiety--;
}

class Dog : public Animal 
{
public:
	void run();
};

void Dog::run()
{
	std::cout << name << " is running\n";
	fatigue++;
	happiness++;
	satiety--;
}

void menu()
{
	std::cout << "***************************\n";
	std::cout << "***1. dog        2. cat****\n";
	std::cout << "***0. quit       **********\n";
}

void catlist()
{
	std::cout << "***************************\n";
	std::cout << "***1. eat        2. sleep**\n";
	std::cout << "***3. play       4. climb**\n";
	std::cout << "***0. quit       **********\n";
}

void doglist()
{
	std::cout << "***************************\n";
	std::cout << "***1. eat        2. sleep**\n";
	std::cout << "***3. play       4. run  **\n";
	std::cout << "***0. quit       **********\n";
}

enum CD{
	DOG,
	CAT
};

int main()
{
	Cat cat;
	Dog dog;
	cat.name = "Lucky";
	dog.name = "Mochi";
	menu();
	int input;
	int choice;
	std::cin >> input;
	while (input)
	{
		switch (input)
		{
		case DOG:
			doglist();
			std::cin >> choice;
			break;
		case CAT:
			catlist();
			std::cin >> choice;
			break;
		default:
			break;
		}
	}


	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class Human {
public:
	std::string name;
	int age;

	Human(std::string name);
	~Human();
};
Human::Human(std::string name)
{
	this->name = name;
	//this指针
	//指向的name是类里面的name
	//这里将函数参数的name赋值给类里面的name
}

Human::~Human()
{
	;
}

int main() 
{
	Human H("ABC");
	Human H1{"EFGDF"};
	Human H2;//no default constructor
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include<string>
class Quote
{
public:
	std::string quote, writer;
	std::ofstream outfile;
	
	Quote();
	~Quote();
	void getquote();
	bool writefile();
	void getwriter();
};

Quote::Quote() {
	outfile.open("d:\\quote.txt", std::ios::out);
}

Quote::~Quote() {
	outfile.close();
}

void Quote::getquote()
{
	std::cout << "Enter the quote.:>";
	std::getline(std::cin, quote);
}

void Quote::getwriter()
{
	std::cout << "Enter the writer.:>";
	std::getline(std::cin, writer);
}

bool Quote::writefile()
{
	if (outfile.is_open())
	{
		outfile << quote << '|' << writer << std::endl;
		return true;
	}
	else
		return false;

}
int main()
{
	Quote Q;
	Q.getquote();
	Q.getwriter();
	if (Q.writefile())
	{
		std::cout << "File writing success.\n";
	}
	else {
		std::cout << "File writing failed.\n";
		return 1;
	}

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

#define FULL 80
class car {
public:
	int tire;
	string color;
	int fuel;
	
	car(void);//构造函数
	int running();
	void warning();
};

int car::running()
{
	cout << "Car is running\n";
	cout << "Fuel left: " << fuel * 100 / FULL << "%\n";
	fuel--;
	return fuel;
}

void car::warning(void)
{
	if (fuel <= 10)
	{
		cout << "warning!\n";
		cout << "add fuel? [Y/N]>:";
		char c;
		cin >> c;
		switch (c)
		{
		case 'Y':
		case'y':
			fuel = FULL;
			cout << "fuel refilled.\n";
			break;
		case'N':
		case'n':
			break;
		default:
			break;
		}
	}
}
car::car()//构造器
{
	tire = 4;
	color = "white";
	fuel = FULL;
}

int main()
{
	car mycar;
	while ((mycar.running()))
	{
		mycar.warning();
	}

	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

double f(int n, double a[], double x)
{
	int i;
	double p = a[0];
	for (i = 1; i <= n; i++)
	{
		p += (a[i] * pow(x, i));
	}
	return p;
}

double f2(int n, double a[], double x)
{
	int i;
	double p = a[n];
	for (i = n; i > 0; i--)
	{
		p = a[i - 1] + x * p;
	}
	return p;
}

int main()
{
	double arr[5] = { 1.1,2.2,3.3,4.4,5.5 };
	double x = 3.3;
	int n = 5;
	cout << f(n, arr, x)<<endl;
	cout << f2(n, arr, x)<<endl;
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;

void init(int (*arr)[5], const int i, const int j)
{
	for (int x = 0; x < i; x++)
	{
		for (int y = 0; y < j; y++)
		{
			arr[x][y] = 0;
		}
	}
}

void menu()
{
	cout << "**********************************" << endl;
	cout << "****1. add A data 2. add B data **" << endl;
	cout << "****3. A+B        4. A-B       ***" << endl;
	cout << "****0. exit    *******************" << endl<<endl;

}

void AddData(int(*A)[5])
{
	int x;
	int y;
	cout << "enter the line:>";
	cin >> x;
	cout << "enter the line:>";
	cin >> y;
	cout << "enter the data:>";
	int data;
	cin >> data;
	A[x][y] = data;
}
void AddAB(int (*A)[5],int (*B)[5],int i,int j)
{
	int x = 0;
	for (x = 0; x < i; x++)
	{
		int y = 0;
		for (y = 0; y < j; y++)
		{
			A[x][y] = B[x][y]+A[x][y];
		}
	}
}

void SubAB(int (*A)[5], int (*B)[5], int i, int j)
{
	int x = 0;
	for (x = 0; x < i; x++)
	{
		int y = 0;
		for (y = 0; y < j; y++)
		{
			A[x][y] -= B[x][y];
		}
	}
}

void display(int A[][5], int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

int main()
{
	const int i = 3;
	const int j = 5;
	int A[i][j];
	int B[i][j];
	init(A,i,j);
	init(B,i,j);
	menu();
	int input;
	cin >> input;
	while (input)
	{
		switch (input)
		{
		case 1:
			AddData(A);
			break;
		case 2:
			AddData(B);
			break;
		case 3:
			AddAB(A, B,i, j);
			break;
		case 4:
			SubAB(A, B, i, j);
			break;
		}
		menu();
		display(A,i,j);
		display(B,i,j);
		cout << "Please choose:>";
		cin >> input;
	}
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;

void init(int (*arr)[5], const int i, const int j)
{
	for (int x = 0; x < i; x++)
	{
		for (int y = 0; y < j; y++)
		{
			arr[x][y] = 0;
		}
	}
}

void menu()
{
	cout << "**********************************" << endl;
	cout << "****1. add A data 2. add B data **" << endl;
	cout << "****3. A+B        4. A-B       ***" << endl;
	cout << "****0. exit    *******************" << endl;

}

void AddData(int(*A)[5])
{
	int x;
	int y;
	cout << "enter the line:>";
	cin >> x;
	cout << "enter the line:>";
	cin >> y;
	cout << "enter the data:>";
	int data;
	cin >> data;
	A[x][y] = data;
}

int main()
{
	const int i = 3;
	const int j = 5;
	int A[i][j];
	int B[i][j];
	init(A,i,j);
	init(B,i,j);
	menu();
	int input;
	cin >> input;
	while (input)
	{
		switch (input)
		{
		case 1:
			AddData(A);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		}
	}
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>

class lover {
public:
	std::string name;
	int height;
	int age;
	char gender;
	int favorability;
	int money;
	int day;

	void initLover();
	void cleaning();
	void date();
	void job();
	void marry();//favor = 100 money = 100
};

void lover::cleaning()
{
	money += 5;
	day+=2;
	favorability -= 2;
}

void lover::date()
{
	money -= 10;
	day += 1;
	favorability += 10;
}

void lover::job()
{
	money += 10;
	day += 5;
}

void lover::marry()
{
	money -= 80;
	favorability += 80;
	day += 1;
}

void display(lover l)
{
	std::cout << "----------------------" << std::endl;
	std::cout <<"name: "<<l.name<<"|| age: " << l.age << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << "height: " << l.height << "|| gender: " << l.gender << std::endl;
	std::cout << "----------------------" << std::endl; 
	std::cout << "money: " << l.money << "|| favorability: " << l.favorability << std::endl;
	std::cout << "\n";
}

void lover::initLover()
{
	age = 28;
	name = "andrew";
	day = 0;
	gender = 'M';
	height = 185;
	money = 0;
	favorability = 1;

}

enum {
	EXIT,
	CLEANING = 1,
	DATE,
	JOB,
	MARRY
};

int main() 
{
	class lover andrew;
	andrew.initLover();
	display(andrew);
	while (andrew.day < 30)
	{
		int x;
		std::cout << "0. exit 1. cleaning\n";
		std::cout << "2. date 3. job\n";
		std::cout << "4. marry\n";
		std::cout << "enter a number:>";
		std::cin >> x;
		switch (x)
		{
		case EXIT:
			std::cout << "exiting game.\n";
			return 0;
			break;
		case CLEANING:
			andrew.cleaning();
			break;
		case DATE:
			andrew.date();
			break;
		case JOB:
			andrew.job();
			break;
		case MARRY:
			andrew.marry();
			break;
		default:
			std::cout << "invalid data! please re-enter.\n";
			break;
		}
		display(andrew);
	}
	if (andrew.favorability < 0)
	{
		std::cout << "your relationship is over because he don't love you anymore.\n";
	}
	else if (andrew.favorability < 10)
	{
		std::cout << "He only like you but not too much.\n";
	}
	else if (andrew.favorability < 50)
	{
		std::cout << "You kept a normal relationship.\n";
	}
	else
	{
		std::cout << "You have a very happy relationship!\n";
	}

	if (andrew.money < 0)
	{
		std::cout << "Andrew is broke, you left him.\n";
	}
	else if (andrew.money < 10)
	{
		std::cout << "Andrew is living a poor life.\n";
	}
	else if (andrew.money<30)
	{
		std::cout << "Andrew is living a normal life.\n";
	}
	else
	{
		std::cout << "Andrew is rich.\n";
	}
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>

class lover {
public:
	std::string name;
	int height;
	int age;
	char gender;
	int favorability;
	int money;
	int day;

	void cleaning();
	void date();
	void job();
	void marry();//favor = 100 money = 100
};

void lover::cleaning()
{
	money += 5;
	day+=2;
	favorability -= 2;
}

void lover::date()
{
	money -= 10;
	day += 1;
	favorability += 10;
}

void lover::job()
{
	money += 10;
	day += 5;
}

void lover::marry()
{
	money -= 100;
	day += 1;
}

void display(lover l)
{
	std::cout << "----------------------" << std::endl;
	std::cout <<"name: "<<l.name<<"|| age: " << l.age << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << "height: " << l.height << "|| gender: " << l.gender << std::endl;
	std::cout << "----------------------" << std::endl; 
	std::cout << "money: " << l.money << "|| favorability: " << l.favorability << std::endl;
}

void initLover(lover l)
{
	l.age = 28;
	l.name = "andrew";
	l.day = 0;
	l.gender = 'M';
	l.height = 185;
	l.money = 0;
	l.favorability = 1;

}

int main() 
{
	class lover andrew;
	initLover(andrew);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define Max 85
class Car {
public:
	std::string color;
	std::string engine;
	unsigned int gas_tank;
	unsigned int wheel;
	
	void setColor(std::string col);
	void setEngine(std::string eng);
	void setWheel(unsigned int wh);
	void fill_tank(int liter);
	void running(void);
	void warning(void);

};

void Car::setColor(std::string col)
{
	color = col;
}

void Car::setEngine(std::string eng)
{
	engine = eng;
}

void Car::setWheel(unsigned int wh)
{
	wheel = wh;
}

void Car::running(void)
{
	std::cout << "The car is running " << 100*gas_tank / 85 << "% gas left.\n";
	gas_tank--;
}

void Car::warning(void)
{
	if (gas_tank <= 10)
	{
		std::cout << 100 * gas_tank / 85 << " gas are left over\n";
		std::cout << "Refill gas tank? [Y/N]:>";
		char i;
		std::cin >> i;
		switch (i)
		{
		case 'Y':
		case 'y':
			fill_tank(Max);
			break;
		case'n':
		case'N':
			break;
		}
	}
}

void Car::fill_tank(int liter)
{
	gas_tank += liter;
}
int main()
{
	Car car1;
	car1.setColor("White");
	car1.setEngine("V8");
	car1.setWheel(4);
	car1.gas_tank = 0;
	std::cout << "Color: " << car1.color << std::endl;
	std::cout << "Engine: " << car1.engine << std::endl;
	std::cout << "Wheel: " << car1.wheel << std::endl;
	std::cout << "Fill tank?[Y/N]>:";
	char c;
	std::cin >> c;
	switch (c)
	{
	case 'Y':
	case 'y':
		car1.fill_tank(Max);
		break;
	case 'N':
	case'n':
		break;
	}
	while (car1.gas_tank)
	{
		car1.running();
		car1.warning();
	}
	std::cout << "The car run out of oil.\n Game over.\n";
	return 0;
}



#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;


template <class T>
T calc(T* x, int n)
{
	T highest = x[0];
	T lowest = x[0];
	int i = 0;
	int t = 0;
	for (i = 0; i < n; i++)
	{
		if (x[n - 1 - i] == '\0')
		{
			t++;
		}

	}
	n -= t;
	for (i = 0; i < n; i++)
	{
		if (highest < x[i])
		{
			highest = x[i];
		}
	}

	for (i = 0; i < n; i++)
	{
		if (lowest > x[i])
		{
			lowest = x[i];
		}
	}
	return highest - lowest;
}



int main()
{
	int arr1[10] = { 1,2,7,4,55,3,54,100,0,-100 };
	char arr2[10] = "acdeb";
	double arr3[5] = { 9.9,8.8,1.1,6.6,5.5 };
	int a = calc(arr1, 10);
	int b = calc(arr2, 10);
	double c = calc(arr3, 5);
	cout << a << endl << b << endl << c << endl;
	return 0;
}



int main()
{
	ifstream infile("d:\\pay.txt",ios::in);
	ofstream outfile("d:\\newpay.txt",ios::out);
	char name[20];
	float pay;
	float raise;
	float raiseAmount;
	float newpay;
	while (infile.getline(name, 20))
	{
		infile >> pay >> raise;
		raiseAmount = (pay * raise / 100);
		newpay = pay + raiseAmount;
		outfile << name << endl<<raiseAmount<<' '<<newpay<<endl;
		infile.ignore(20, '\n');
	}
	infile.close();
	outfile.close();
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


template <class T>
T calc(T a, T b)
{
	if (a > b)
	{
		return a - b;
	}
	else
	{
		return b - a;
	}
}

int main()
{
	int a;
	int b;
	cin >> a >> b;
	int c = calc(a, b);
	cout << c<<endl;
	char c1 = 'a';
	char c2 = 'b';
	int c3 = calc(c1, c2);
	cout << c3<<endl;
	float q1 = 5.555;
	float q2 = 1.111;
	float q3 = calc(q1, q2);
	cout << q3 << endl;
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int calc(int);
int calc(int, int);
int calc(int, int, int);

int main()
{
	int a, b, c;
	std::cout << "enter a number:>";
	std::cin >> a;
	std::cout<<calc(a)<<std::endl;
	std::cout << "enter two numbers:>";
	std::cin >> a >> b;
	std::cout << calc(a, b) << std::endl;
	std::cout << "enter three numbers:>";
	std::cin >> a >> b >> c;
	std::cout << calc(a, b, c) << std::endl;
	return 0;
}

int calc(int a)
{
	return a * a;
}
int calc(int a , int b)
{
	return a * b;
}
int calc(int a, int b, int c)
{
	return a + b + c;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	//F == C *9/5 + 32
	cout << "enter the temperature[XX.XX C] or [XX.XX F]:> ";
	double tempIn, tempOut;
	char typeIn, typeOut;
	float ratio = 5 / 8;
	int addon = 32;
	cin >> tempIn >> typeIn;
	cout << tempIn << typeIn;
	switch (typeIn)
	{
	case 'C':
	case'c':
		tempOut == tempIn * ratio + addon;
		typeOut == 'F';
		break;
	case'F':
	case'f':
		tempOut == (tempIn - addon) / ratio;
		typeOut == 'C';
		break;
	default:
		break;
	}
	cout << endl << tempOut << typeOut << endl;
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	cout << "Delete all your data [Y/N]:>";
	char c;
	cin >> c;
	switch (c)
	{
	case 'Y':
	case 'y':
		cout << "This isn't a good choice"<<endl;
		break;
	case 'n':
	case'N':
		cout << "Good choice!" << endl;
		break;
	default:
		cout << "invalid input!" << endl;
		break;
	}
	return 0;
}


#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream of("d:\\nums.txt", ios::out);
	int num;
	cout << "enter a number:>";
	while (cin >> num)
	{
		of << num<<endl;
		cout << "next number? (ctrl z to quit):>";
	}
	of.close();

	ifstream ifp("d:\\nums.txt", ios::in);
	while (ifp>>num)
	{
		cout << num << endl;
	}
	//creat a file and read numbers into the file till ctrl z is entered.
	//retrieve and print the file
	return 0;
}

#include<iostream>
using namespace std;

void one(int a)
{
	cout << "Program one"<<endl<<endl;
}
void two(int a)
{
	cout << "Program two" << endl << endl;
}
void three(int a)
{
	cout << "Program three" << endl << endl;
}
void four(int a)
{
	cout << "Program four" << endl << endl;
}

int main()
{
	int input;
	void (*pf[4])(int) = { one,two,three,four };
	cout << "enter a number from 1-5:>";
	cin >> input;
	while(input)
	{
		(*pf[input - 1])(input);
	cout << "enter a number from 1-5, 0 to quit:>";
	cin >> input;
	}
	return 0;
}
#include<iostream>
using namespace std;

void one(int);
void two(int);
void three(int);
void four(int);
void five(int);

int main()
{
	int choice;
	void(*f)(int) = one;
	cout << "enter a number from 1 to 5:>";
	cin >> choice;
	while (choice)
	{
		switch(choice)
		{
	case 1:
		f = one;
		break;
	case 2:
		f = two;
		break;
	case 3:
		f = three;
		break;
	case 4:
		f = four;
		break;
	case 5:
		f = five;
	default:
		cout << "invalid data!" << endl;
		break;
		}
		f(choice);
		cout << "enter a number from 1 to 5, 0 to quit:>";
		cin >> choice;
	}
	return 0;
}

void one(int n)
{
	cout << "you entered " << n << " and you are in function one" << endl;
}
void two(int n)
{
	cout << "you entered " << n << " and you are in function two" << endl;
}
void three(int n)
{
	cout << "you entered " << n << " and you are in function three" << endl;
}
void four(int n)
{
	cout << "you entered " << n << " and you are in function four" << endl;
}
void five(int n)
{
	cout << "you entered " << n << " and you are in function five" << endl;
}

#include<iostream>
using namespace std;

inline int volume(int x = 1, int y = 1, int z = 1) { return x * y * z; }

int main()
{
	cout <<"The default volume is " << volume() << endl;
	int input;
	cout << "enter a number:>";
	cin >> input;
	while (input)
	{
		cout << volume(input, input, input)<<endl;
		cout << "Enter a number:>";
		cin >> input;
	}
	return 0;
}
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	fstream fp("d:\\test.txt", ios::in | ios::out);
	if (!fp)
	{
		cerr << "open file failed." << endl;
		return 0;
	}
	fp << "testing";
	char ch[100];
	fp.seekg(ios::beg);
	fp >> ch;
	cout << ch << endl;
	fp.close();
	return 0;
}

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream out;
	out.open("d:\\test.txt");
	int i = 0;
	for (i; i < 10; i++)
		out << i;
	return 0;
}
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream in;
	in.open("d:\\test.txt");
	if (!in)
	{
		cout << "open file failed." << endl;
	}
	char x;
	while (in >> x)
		cout << x;
	cout << endl;
	in.close();

	return 0;
}
#include<iostream>
using namespace std;
template <class T>

void printfarr(T* arr, const int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		cout << arr[i]<<' ';
	}
	cout << endl;
}

int main()
{
	const int a = 5, b = 6, c = 7;
	int arr1[a] = {1,2,3,4,5};
	float arr2[b] = {1.1,2.2,3.3,4.4,5.5,6.6};
	char arr3[c] = "HELLO";
	printfarr(arr1, a);
	printfarr(arr2, b);
	printfarr(arr3, c);

	return 0;
}
#include<iostream>
using namespace std;

template <class T>

T max(T x, T y, T z)
{
	T largest = x;
	if (y > largest)
		largest = y;
	if (z > largest)
		largest = z;
	return largest;
}

int main()
{
	int a, b, c;
	cout << "enter three int:"<<endl;
	cin >> a>> b>> c;
	cout << "The largest is " << max(a, b, c) << endl;
	char x, y, z;
	cout << "enter three chars:" << endl;
	cin >> x >> y >> z;
	cout << "The largest is " << max(x, y, z) << endl;
	float q, w, e;
	cout << "Enter three floats:" << endl;
	cin >> q >> w >> e;
	cout << "The largest is " << max(q, w, e) << endl;
	return 0;
}

#include<iostream>
using namespace std;
#include<iostream>
using namespace std;
inline double twice(double x) { return x * x; }
inline int twice(int x) { return x * x; }
inline int twice(int x, int y) { return x + y; }
inline int twice(int x, int y,int z) { return x + y+z; }
int main()
{
	//overloaded function
	cout << twice(5) << endl;
	cout << twice(5.5) << endl;
	cout << twice(5,6) << endl;
	cout << twice(5, 6, 7) << endl;
	return 0;
}

#include<iostream>
using namespace std;

int num = 5;

int main()
{
	int num = 3;
	cout << "num in local scope is " << num << endl;
	cout << "num in global scope is " << ::num << endl;
	return 0;
}

#include<iostream>
using namespace std;

inline double cube(const double s) { return s * s * s; }

int main()
{
	cout << "enter the side length of a cube:>";
	double side;
	cin >> side;
	cout << "volume of cube with side " << side << "is " << cube(side) << endl;
	//inline并不赋值因为么有赋值符号
	cout << side << endl;
	return 0;
}

void GetInfo(char*, float&, float&, float&, char*);
void calc(float&, float&, float&, float, float, float); 
int main()
{
	char last[15] = "Bao";
	char first[10] = "Di";
	float money = 200.2523;
	int num = 16;
	cout << left << setw(15) << last << setw(10) << first << endl;
	cout << setprecision(2) << showpoint << fixed;
	cout << money << endl;
	cout << setbase(8) << "num in octal is : " << num << endl;
	cout << setbase(16) << "num in hexadecimal is : " << num << endl;
	char name[20];
	float hours;
	float rate;
	float tax;
	char department[15];
	GetInfo(name, hours, rate, tax, department);
	cout << "The name is " << name<<endl;
	cout << "hours is " << hours << endl;
	cout << "rate is " << rate << endl;
	cout << "tax is " << tax << endl;
	cout << "department is " << department << endl;
	float GrossPay;
	float TaxAmount;
	float NetPay;
	calc(GrossPay, TaxAmount, NetPay, hours, rate, tax);
	cout << "Gross pay is " << GrossPay << endl;
	cout << "Tax Amount is " << TaxAmount << endl;
	cout << "Net Pay is " << NetPay << endl;
	return 0;
}
void GetInfo(char* name, float& hours, float& rate, float& tax, char* dpt)
{
	cout << "please enter the name : > ";
	cin.getline(name, 20);
	cout << "please enter the hours : > ";
	cin >> hours;
	cout << "please enter the rate : > ";
	cin >> rate;
	cout << "please enter the tax : > ";
	cin >> tax;
	cout << "please enter the department : > ";
	cin.ignore(20, '\n');
	cin >> dpt;
}

void calc(float& GrossPay, float& TaxAmount, float& NetPay, float hours, float rate, float tax)
{
	GrossPay = hours * rate;
	TaxAmount = GrossPay * tax / 100;
	NetPay = GrossPay - TaxAmount;
}



void swapbyvalue(int, int);
void swapbyptr(int*, int*);
void swapbyref(int&, int&);
void getnames(char*, char*);

int main()
{
	int a, b;
	cout << "enter two numbers:>";
	cin >> a >> b;
	cout << "the two numbers are " << a << "\t" << b << endl;
	swapbyvalue(a, b);
	cout << "the two numbers after swapby value are " << a << "\t" << b << endl;
	swapbyptr(&a, &b);
	cout << "the two numbers after swapbyptr are " << a << "\t" << b << endl;
	swapbyref(a, b);
	cout << "the two numbers after swapbyref are " << a << "\t" << b << endl;
	char first[10], last[15];
	cout << "before the names are entered the values are " << first << ' ' << last << endl;
	getnames(first, last);
	cout << "after the names are entered the values are " << first << ' ' << last << endl;
	return 0;
}

void swapbyvalue(int x, int y)
{
	int t = x;
	x = y;
	y = t;
}
void swapbyptr(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void swapbyref(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

void getnames(char* f, char* l)
{
	cin.ignore(10, '\n');
	cout << "enter a first name:>";
	cin.getline(f, 10);
	cout << "enter a last name:>";
	cin.getline(l, 15);
}
int main()
{
	int n = 28;
	cout << n << " in hexadecimal is: " << hex << n << endl;
	cout << uppercase << "hex in uppercase is " << n << endl;
	cout << n << endl;
	cout << nouppercase << "hex back in lowercase is " << n << endl;
	cout << n << " in octal is: " << oct << n << endl;
	cout << n << " in decimal is: " << dec << n << endl<<endl;
	cout << setbase(16) << "hex is " << n << endl;
	cout << uppercase << "hex in uppercase is " << n << endl;
	cout << nouppercase << "hex back in lower case is " << n << endl;
	cout << setbase(8) << "octal is " << n << endl;
	cout << setbase(10) << "decimal is " << n << endl;
	cout <<  n << endl;
	return 0;
}

int main()
{
	float num1 = 123456;
	float num2 = 12.3456;
	float num3 = 234.567;
	cout << "num1 unformatted is : " << num1 << endl;
	cout << "num2 unformatted is : " << num2 << endl;
	cout << "num3 unformatted is : " << num3 << endl;

	cout << setprecision(2) << showpoint << fixed;
	cout << "num1 formatted is: $" << num1 << endl;
	cout << "num2 formatted is: $" << num2 << endl;
	cout << "num3 formatted is: $" << num3 << endl<<endl;
	return 0;
}
int main()
{
	char words[11] = "Hello Seth";
	float num = 23.45;
	//setw only applies to each field and must be repeated, default justification is right
	cout << "right justified: " << endl;
	cout << setw(5) << words << endl;
	cout << setw(10) << words << endl;
	cout << setw(15) << words << endl;
	cout << setw(25) << words << endl;
	cout << setw(15) << num << endl;
	cout << setw(25) << num << endl;
	cout << endl << endl;
	//to left justify
	cout << "left justified: " << endl;
	cout << setw(5) << left << words << endl;
	cout << setw(15) << words << endl;
	cout << setw(25) << words << endl;
	cout << setw(15) << num << endl;
	cout << setw(25) << num << endl;
	cout << endl << endl;
	//to reset justification
	cout << "justification reset to right:" << endl;
	cout << setw(15) << right << words << endl;
	cout << setw(20) << words << endl;
	cout << setw(15) << num << endl;
	cout << setw(20) << num << endl;
	return 0;
}

int main()
{
	double num1 = 1234.5678;
	double num2 = 98.7654321;
	int i = 0;
	for (i = 2; i < 10; i++)
	{
		cout << setprecision(i);
		cout << "With precision " << i << " num 1 is " << num1 << endl;
		cout << "With precision " << i << " num 2 is " << num2 << endl;
		cout << endl;
	}
	return 0;
}

int main()
{
	float num1 = 1234.567;
	float num2 = 57.41111;
	for (int i = 2; i <= 7; i++)
	{
		cout.precision(i);//specifies the number of digits to print
		cout << "cout with precision" << i << " is " << num1 << endl;
		cout << "cout with precision" << i << " is " << num2 << endl;
		cout << endl;
	}
	return 0;
}
int main()
{
	char c;
	cout << "enter a line of text" << endl;
	while ((c = cin.get()) != '\n')
		cout.put(c);
	cout << endl << "loop is done" << endl;
	return 0;
}

int main()
{
	const int SIZE = 10;
	char line[SIZE];
	cout << "Please enter a text:>";
	cin >> line;
	cout << line << endl;
	cin.ignore(SIZE,'\n');
	cout << "Please enter another text:>";
	cin.getline(line,SIZE);
	cout << line << endl;
	return 0;
}
int main()
{
	int width = 4;
	char str[20];
	cout << "Please enter a text:>";
	cin.width(5);
	while (cin >> str)
	{
		cout.width(width++);
		cout << str << endl;
		cin.width(5);
	}
	return 0;
}

int main()
{
	double result = sqrt(3.0);
	cout << "square root 3 is equals to:\n" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout.precision(i);//几位的精度
		cout << result << endl;
	}
	return 0;
}

int main()
{
	//创建一个字符数组，输入20个+字符，然后count输入了多少个字符(20个)，输出多少个，输出这个字符串
	const int SIZE = 50;
	char arr[SIZE];
	cout << "Please enter any text.:>";
	cin.read(arr, 20);
	cout<<"The numbers of character you entered are: "<<cin.gcount()<<endl;
	cout << "The text is: ";
	cout.write(arr,20);
	return 0;
}

int main()
{
	char c;
	cout << "Please enter any text.:>";
	while (cin.peek() != '\n')
	{
		cout << (c = cin.get());
	}
	return 0;
}

int main()
{
	char buf[20];
	cin.ignore(7);//忽略前7个字符
	cin.getline(buf, 10);//提取10个字符（实际是9个，因为最后一个默认是\0
	cout << buf<<endl;//这里输出提取到的9个字符
	return 0;
}

int main()
{
	int sum = 0;
	cout << "Please enter an array of intergers and any spaces.:>";
	int i;
	while (cin >> i)
	{
		sum += i;
		while (cin.peek() == ' ')//cin.peek 是瞅一眼缓冲区的是不是' '
		{
			cin.get();//cin.get就是把第一个字符从缓冲区拿出来，相当于getchar
		}
		if (cin.peek() == '\n')//瞅一眼如果是\n就跳出循环
			break;
	}
	cout << "The sum is:" << sum << endl;
	return 0;
}

int main()
{
	int a = 0;
	cout << "hello world\n";
	cin >> a;
	return 0;
}

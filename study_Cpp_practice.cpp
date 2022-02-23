#define _CRT_SECURE_NO_WARNINGS
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

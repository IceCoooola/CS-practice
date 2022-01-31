#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
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

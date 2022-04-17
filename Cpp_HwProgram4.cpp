#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Complex
{
public:
	Complex(float = 0, float = 0);
	//A default constructor that uses default arguments 
	//in case no initializers are included in the main.
	
	//>>   <<   +   -   *   ==   !=  overloaded
	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, Complex&);
	Complex operator+(Complex&);
	Complex operator-(Complex&);
	Complex operator*(Complex&);
	Complex& operator*=(Complex&);
	const Complex& operator=(const Complex&);
	bool operator==(Complex&);
	bool operator!=(Complex&);
	Complex& operator++();
	Complex operator++(int);
	//overload the preincrement and postincrement operators ++ 
	//which will change the value of the complex number to its cube.
private:
	float real;
	float img;
};

std::ostream& operator<<(std::ostream& os, const Complex& obj)
{
	if (obj.img >= 0)
		os << obj.real << '+' << obj.img << "i.\n";
	else
		os << obj.real << obj.img << "i.\n";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& obj)
{
	is >> obj.real >> obj.img;
	return is;
}

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
	return Complex((real * x.real - img * x.img), (real * x.img + img * x.real));
}

Complex& Complex::operator*=(Complex& rhs)
{
	*this = *this * rhs;
	return *this;
}

bool Complex::operator==(Complex& x)
{
	return (real == x.real) && (img == x.img);
}

bool Complex::operator!=(Complex& x)
{
	return (real != x.real) || (img != x.img);
}

const Complex& Complex::operator=(const Complex& x)
{
	real = x.real;
	img = x.img;
	return *this;
}

Complex::Complex(float n, float d)
{
	real = n;
	img = d;
}

Complex& Complex::operator++()
{
	Complex temp = *this;
	*this *= temp;
	*this *= temp;
	return *this;
}
Complex Complex::operator++(int)
{
	Complex temp = *this;
	*this *= temp;
	*this *= temp;
	return temp;
}

int main()
{
	Complex x(3.14, 1.26);
	Complex y(0.5, 3.1);
	std::cout << "Two complex number created. The two complex numbers are:\n";
	std::cout << x << y;
	//test overloaded operator +
	Complex z = x + y;
	std::cout << "\nThe sum of those two complex numbers is:\n";
	std::cout<<z;
	std::cout << "\nThe difference of those two complex numbers is:\n";
	//test overloaded operator -
	z = x - y;
	std::cout << z;
	std::cout << "\nThe product of those two complex numbers is:\n";
	//test overloaded operator *
	z = x * y;
	std::cout << z;
	//test overloaded operator preincrement ++
	std::cout << "\nAfter preincrement. Those two complex numbers are:\n";
	std::cout << ++x << ++y;
	//test overloaded operator ==
	if (x == y)
	{
		std::cout << "those two complex numbers are equal.\n";
	}
	else
	{
		std::cout << "those two complex numbers are different.\n";
	}
	Complex a(2.5, 1.5), b;
	b = a;
	std::cout << "two new complex number created. The two new complex numbers are:\n";
	std::cout << b << a;
	//test overloaded operator !=
	if (a != b)
	{
		std::cout << "those two complex numbers are not the same.\n";
	}
	else
	{
		std::cout << "those two complex numbers are the same.\n";
	}
	//test overloaded operator postincrement ++
	std::cout << "those two complex numbers before postincrement are:\n" << a++ << b++;
	std::cout << "after postincrement are:\n" << a << b;
	return 0;
}

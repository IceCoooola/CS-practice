#include<iostream>
#include<assert.h>

class Rational 
{
public:
	Rational();//default constructor set value to 0/1
	Rational(int numerator, int denominator);//constructor assert denominator can't be 0
	Rational(const Rational& other);//constructor copy other to this
	~Rational();
	Rational& operator=(const Rational& other);//overload operator =, which assigns other to this
	Rational operator+(const Rational& other);//overload operator +, return a value of the sum of two rational numbers
	Rational operator-(const Rational& other);//overload operator -, return a value of the difference of two rational numbers
	Rational operator*(const Rational& other);//overload operator *, return a value of the product of two rational numbers
	Rational operator/(const Rational& other);//overload operator /, return a value of the quotient of two rational numbers
	Rational operator+=(const Rational& other);//overload operator +=, add other to this
	Rational operator-=(const Rational& other);//overload operator -=, subtract other from this
	Rational operator*=(const Rational& other);//overload operator *=, multiply this by other
	Rational operator/=(const Rational& other);//overload operator /=, divide this by other
	int operator==(const Rational& other);//if two rational numbers are equal, return 1, else return 0
	friend std::ostream& operator<<(std::ostream&, const Rational& other);//overload operator <<, print out the value of this
	friend std::istream& operator>>(std::istream&, Rational& other);//overload operator >>, read in the value of this
	void rationaize();//rationaize rational number, and if negative number, set numerator to negative
private:
	int numerator;
	int denominator;
};

Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

Rational::Rational(const Rational& other)
{
	numerator = other.numerator;
	denominator = other.denominator;
}

Rational::Rational(int numerator, int denominator)
{
	assert(denominator);
	this->numerator = numerator;
	this->denominator = denominator;
	rationaize();
}

Rational::~Rational()
{
	;
}


Rational& Rational:: operator=(const Rational& other)
{
	numerator = other.numerator;
	denominator = other.denominator;
	return *this;
}

Rational Rational::operator+(const Rational& other) 
{
	Rational result;
	result.numerator = numerator * other.denominator + other.numerator * denominator;
	result.denominator = denominator * other.denominator;
	result.rationaize();
	return result;
}

Rational Rational::operator-(const Rational& other)
{
	Rational result;
	result.numerator = numerator * other.denominator - other.numerator * denominator;
	result.denominator = denominator * other.denominator;
	result.rationaize();
	return result;
}

Rational Rational::operator*(const Rational& other)
{
	Rational result;
	result.numerator = numerator * other.numerator;
	result.denominator = denominator * other.denominator;
	result.rationaize();
	return result;
}

Rational Rational::operator/(const Rational& other)
{
	Rational result;
	result.numerator = numerator * other.denominator;
	result.denominator = denominator * other.numerator;
	result.rationaize();
	return result;
}

Rational Rational::operator+=(const Rational& other)
{
	numerator = numerator * other.denominator + other.numerator * denominator;
	denominator = denominator * other.denominator;
	rationaize();
	return *this;
}

Rational Rational::operator-=(const Rational& other)
{
	numerator = numerator * other.denominator - other.numerator * denominator;
	denominator = denominator * other.denominator;
	rationaize();
	return *this;
}


Rational Rational::operator*=(const Rational& other)
{
	numerator = numerator * other.numerator;
	denominator = denominator * other.denominator;
	rationaize();
	return *this;
}

Rational Rational::operator/=(const Rational& other)
{
	numerator = numerator * other.denominator;
	denominator = denominator * other.numerator;
	rationaize();
	return *this;
}

int Rational::operator==(const Rational& other)//return 1 if ture, return 0 if false
{
	
	if(numerator == other.numerator && denominator == other.denominator)
		return 1;
	else
		return 0;
}

std::ostream& operator<<(std::ostream& o, const Rational& other)
{
	if (other.numerator == 0)
	{
		o << "0";
		return o;
	}
	else if (other.denominator == 1)
	{
		o << other.numerator;
		return o;
	}
	else 
	{
		o << other.numerator << "/" << other.denominator;
	}
	return o;
}

std::istream& operator>>(std::istream&, Rational& other)
{
	std::cin >> other.numerator;
	getchar();
	std::cin >> other.denominator;
	other.rationaize();
	return std::cin;
}

void Rational::rationaize()
{
	if (numerator == 0)
		return;
	if (numerator > denominator)
	{
		int dividend = denominator;
		int remainder = numerator % denominator;
		while (remainder)
		{
			int t = remainder;
			remainder = dividend % remainder;
			dividend = t;
		}
		numerator /= dividend;
		denominator /= dividend;
	}
	else
	{
		int dividend = numerator;
		int remainder = denominator % numerator;
		while (remainder)
		{
			int t = remainder;
			remainder = dividend % remainder;
			dividend = t;
		}
		numerator /= dividend;
		denominator /= dividend;
	}
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}

}


int main()
{
	std::cout << "two rational number created. one set to default, other set to 5/5\n";
	Rational a, b(1,2);
	std::cout << "a = " << a << " b = " << b << std::endl;
	a = b;
	std::cout <<"test operator =, assign a = b\n";
	std::cout << "now a is: " << a<<std::endl;
	std::cout <<"test operator +, add a and b\n";
	Rational c = a + b;
	std::cout << "the sum is " << c << std::endl;
	std::cout << "test operator -, subtract a and c\n";
	Rational d = a - c;
	std::cout << "the difference is " << d << std::endl;
	Rational e(8,15);
	std::cout << "test operator *, multiply a(1/2) and e(8/15)\n";
	Rational f = a * e;
	std::cout << "f = " << f<<std::endl;
	std::cout << "test operator /, divide a(1/2) and e(8/15)\n";
	f = a / e;
	std::cout << "f = " << f << std::endl;
	std::cout << "test operator +=, a+=e\n";
	a += e;
	std::cout << "a = " << a << std::endl;
	std::cout << "test operator -=, b(1/2)-=a(31/30)\n";
	b -= a;
	std::cout << "b = " <<b<< std::endl;
	std::cout << "test operator *=, e(8/15)-=a(31/30)\n";
	e *= a;
	std::cout << "e = " << e << std::endl;
	Rational g;
	std::cout << "test cin>>. enter a rational numer (x/y):>";
	std::cin >> g;
	std::cout << "you entered: " << g << std::endl;
	std::cout<<"test operator ==, a(31/30)==g(x/y)?\n";
	if (a == g)
	{
		std::cout << "a == g\n";
	}
	else
	{
		std::cout << "a != g\n";
	}
	std::cout << "test operator /=, a/=g\n";
	a /= g;
	std::cout << "a = " << a<<std::endl;
	//+ - * / += -= *= /= == cin>> 
	
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Complex 
{
public:
	Complex(float = 0, float = 0);//A default constructor that uses default arguments in case no initializers are included in the main.
	Complex complexAdd(Complex&);	//Add two complex numbers and store the sum.
	Complex complexSub(Complex&);//Subtract two complex numbersand store the difference.
	Complex complexMul(Complex&);//Multiply two complex numbersand store the product.
	void complexPrint();//Print a complex number in the form a + bi or a – bi 
	void complexCube();//Change a complex number to its cube.
private:
	float real;
	float img;
};

Complex::Complex(float n, float d)
{
	real = n;
	img = d;
}

Complex Complex::complexAdd(Complex& x)
{
	return Complex(real + x.real, img + x.img);
}

Complex Complex::complexSub(Complex& x)
{
	return Complex(real - x.real, img - x.img);
}

Complex Complex::complexMul(Complex& x)
{
	return Complex((real * x.real - img * x.img), (real * x.img + img * x.real));
}

void Complex::complexPrint()
{
	if (img >= 0)
	std::cout << real << '+' << img << "i.\n";
	else
	std::cout << real << img << "i.\n";
}

void Complex::complexCube()
{
	Complex temp = Complex(real, img);
	temp = complexMul(temp);
	temp = complexMul(temp);
	real = temp.real;
	img = temp.img;
}

int main()
{
	Complex x(3.14, 1.26);
	Complex y(0.5, 3.1);
	std::cout << "Two complex number created. The two complex numbers are:\n";
	x.complexPrint();
	y.complexPrint();
	Complex z = x.complexAdd(y);
	std::cout << "\nThe sum of those two complex numbers is:\n";
	z.complexPrint();
	std::cout << "\nThe difference of those two complex numbers is:\n";
	z = x.complexSub(y);
	z.complexPrint();
	std::cout << "\nThe product of those two complex numbers is:\n";
	z = x.complexMul(y);
	z.complexPrint();
	std::cout << "\nAfter cubed. Those two complex numbers are:\n";
	x.complexCube();
	y.complexCube();
	x.complexPrint();
	y.complexPrint();
	return 0;
}

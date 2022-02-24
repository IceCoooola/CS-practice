#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<typeinfo>
using namespace std;
//function template to print an array
//works for multiple data types

/*
The third new function template should sort the array data in descending order.  
The fourth new function template should save the array data to a text file.  
The fifth new function template should retrieve the array data from the text file. 
Output should include the smallest and second smallest values for each array along 
with all three arrays being printed out in descending order twice, 
once before the text file is saved and once after the array is retrieved from the text file. 
*/

//first function
template<class T>
void InitArray(T* a, const int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Please enter a " << typeid(*a).name() << " :>";
		cin>>a[i];
	}
}

//second function
template <class T>
void PrintSmall(T* a, const int n)
{
	T smallest = a[0];//smallest
	T small;//second smallest
	T sum = a[0];
	int i;
	for (i = 1; i < n; i++)
	{
		sum+= a[i];//compute the sum
	}
	T largestSub = sum - a[0];
	//the largest number is the sum minus the smallest number
	T temp;
	for (i = 0; i < n; i++)
	{
		if (a[i] == '\0')
		{
			//T might be type of char
			break;
		}
		temp = sum - a[i];
		if (largestSub < temp)
		{
			smallest = a[i];
			largestSub = temp;
		}
	}
	sum -= smallest;
	if (a[0] != smallest)//make sure smallest is not the first element
	{
		largestSub = sum - a[0];
		small = a[0];

	}
	else
	{
		largestSub = sum - a[1];
		small = a[1];
	}

	for (i = 0; i < n; i++)
	{
		if (a[i] == '\0')
		{
			//check for T might be char
			break;
		}
		if (a[i] == smallest)
		{
			continue;
		}
		temp = sum - a[i];
		if (largestSub < temp)
		{
			small = a[i];
			largestSub = temp;
		}
	}
	cout <<"The smallest is: " << smallest << endl;
	cout <<"The second smallest is: " << small << endl;
}

template <class T>

void printarray(T* a, const int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}

int main()
{
	const int n1 = 6, n2 = 6, n3 = 6;
	int a[n1];
	float b[n2];
	char c[n3];
	InitArray(a,n1);	
	InitArray(b,n2);	
	InitArray(c,n3);	
	PrintSmall(a,n1);
	PrintSmall(b,n2);
	PrintSmall(c,n3);
	cout << "the integer array" << endl;
	printarray(a, n1);
	cout << "the float array" << endl;
	printarray(b, n2);
	cout << "the string is" << endl;
	printarray(c, n3);
	return 0;
}
/*
the integer array
2  4  6  8  10
the float array
1.1  2.2  3.3  4.4  5.5  6.6  7.7
the string is
H  E  L  L  O
*/

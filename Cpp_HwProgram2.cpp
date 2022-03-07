#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<typeinfo>
#include<fstream>
using namespace std;

 


//The first new function template should allow the user to enter the array data from the keyboard.
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

//The second new function template should print the smallest and second smallest values for an array without sorting. 
template <class T>
void PrintSmall(T* a, const int n)
{
	T smallest = a[0];//smallest
	T SecondSmall;//second smallest
	int i;
	int num = n;
	for (i = 0; i < num; i++)
	{
		if (smallest > a[i])
		{
			smallest = a[i];
		}
	}
	if (a[0] != smallest)//make sure smallest is not the first element
	{
		SecondSmall = a[0];
	}
	else
	{
		SecondSmall = a[1];
	}
	for (i = 0; i < num; i++)
	{
		if (a[i] == smallest)
		{
			continue;
		}
		if (SecondSmall > a[i])
		{
			SecondSmall = a[i];
		}
	}
	cout <<"The smallest is: " << smallest << endl;
	cout <<"The second smallest is: " << SecondSmall << endl;
}

//The third new function template should sort the array data in descending order.
template<class T>
void SortArr(T* a, const int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < n - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				T temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

//The fourth new function template save the array data to a text file.  
template<class T>
void SaveText(T* a, const int n, string filename)
{
	ofstream outfile(filename, ios::out);
	for (int i = 0; i < n; i++)
	{
		outfile << a[i]<<endl;
	}
	outfile.close();
}

//The fifth new function template should retrieve the array data from the text file. 
template<class T>
void ReadText(T* a, const int n, string filename)
{
	ifstream infile(filename, ios::in);
	for (int i = 0; i < n; i++)
	{
		T temp;
		infile>>a[i];
	}
	infile.close();
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
	const int n1 = 6, n2 = 7, n3 = 8;
	int a[n1];
	float b[n2];
	char c[n3];
	InitArray(a,n1);	
	InitArray(b,n2);	
	InitArray(c,n3);	
	PrintSmall(a,n1);
	PrintSmall(b,n2);
	PrintSmall(c,n3);
	SortArr(a, n1);
	SortArr(b, n2);
	SortArr(c, n3);
	cout <<endl<<"The array has been sorted." << endl;
	cout << "the integer array" << endl;
	printarray(a, n1);
	cout << "the float array" << endl;
	printarray(b, n2);
	cout << "the string is" << endl;
	printarray(c, n3);

	SaveText(a, n1,"d:\\intArr.txt");
	SaveText(b, n2, "d:\\floatArr.txt");
	SaveText(c, n3, "d:\\charArr.txt");
	int a2[n1];
	float b2[n2];
	char c2[n3];
	ReadText(a2, n1, "d:\\intArr.txt");
	ReadText(b2, n2, "d:\\floatArr.txt");
	ReadText(c2, n3, "d:\\charArr.txt");
	cout << endl << "The array has been readed." <<endl;
	cout << "the integer array" << endl;
	printarray(a2, n1);
	cout << "the float array" << endl;
	printarray(b2, n2);
	cout << "the string is" << endl;
	printarray(c2, n3);
	return 0;
}

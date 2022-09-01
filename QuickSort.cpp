#define CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<time.h>
using namespace std;

void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = temp;
	}
}


template<class T>
int partSort3(T* arr, int left, int right)
{

}

//digging hole method
template<class T>
int partSort2(T* arr, int left, int right)
{
	//set the left most number as key
	T key = arr[left];
	//dig the left position as hole
	while (left < right)
	{
		//have to start finding from right
		//find the number smaller than key from right
		while (left < right && arr[right] >= key)
		{
			--right;
		}
		//put the smaller number in left position and take the right position as the hole
		arr[left] = arr[right];
		//find the number larger than key from left 
		while (left < right && arr[left] <= key)
		{
			++left;
		}
		//put the larger number into right position and left position become a hole
		arr[right] = arr[left];
	}
	//now we put key into hole position
	arr[left] = key;
	//and return to the sorted position
	return left;
	
}

//hoare method 
template<class T>
int partSort1(T* arr, int leftIndex, int rightIndex)
{
	//set the leftmost number as key
	T key = arr[leftIndex];
	//record the leftmost index
	int begin = leftIndex;
	while (leftIndex < rightIndex)
	{
		//we have to have right move first
		//otherwise it will end up with a number that is larger than key
		while (leftIndex < rightIndex && arr[rightIndex] >= key)
		{
			//find the number smaller than key from right
			--rightIndex;
		}
		while (leftIndex < rightIndex && arr[leftIndex] <= key)
		{
			//find the number larger than key from left
			++leftIndex;
		}
		//swap these two numbers
		swap(arr[leftIndex], arr[rightIndex]);
	}
	//and swap the key with the final index
	swap(arr[begin], arr[leftIndex]);
	//return to sorted position
	return leftIndex;
}

template<class T>
void _quickSort(T* arr, const int left, const int right)
{
	if (left >= right)
	{
		return;
	}
	//int key = partSort(arr, left, right);
	int key = partSort1(arr, left, right);
	//recursively sort the array
	//devide the array by two part and sort it
	_quickSort(arr, left, key-1);
	_quickSort(arr, key +1, right);
	
}


template<class T>
void quickSort(T* arr, const int size)
{
	assert(arr);
	_quickSort(arr, 0, size - 1);
}

int main()
{
	int* arr1 = new int[100000];
	for (int i = 0; i < 100000; i++)
	{
		arr1[i] = rand();
	}
	clock_t t;
	t = clock();
	quickSort(arr1, 100000);
	/*for (auto e : arr)
	{
		cout << e<<" ";
	}*/
	t = clock() - t;
	cout << t<<endl;

	int* arr2 = new int[100000];
	for (int i = 0; i < 100000; i++)
	{
		arr2[i] = rand();
	}
	clock_t t2;
	t2 = clock();
	InsertSort(arr2, 100000);
	t2 = clock() - t2;
	cout << t2 << endl;

	return 0;
}

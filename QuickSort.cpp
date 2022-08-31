#define CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

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

//horea method 
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
	//int key = partSort1(arr, left, right);
	int key = partSort2(arr, left, right);
	//recursively sort the array
	//devide the array by two part and sort it
	_quickSort(arr, left, key-1);
	_quickSort(arr, key +1, right);
	
}


template<class T>
void quickSort(T* arr, const int size)
{
	_quickSort(arr, 0, size - 1);
}

int main()
{
	int arr[] = { 1,5,7,432,22,-3,6,3 };
	quickSort(arr, sizeof(arr)/sizeof(int));
	for (auto e : arr)
	{
		cout << e<<endl;
	}
	return 0;
}

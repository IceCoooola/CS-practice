#define CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
int partSort(T* arr, int leftIndex, int rightIndex)
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
			rightIndex--;
		}
		while (leftIndex < rightIndex && arr[leftIndex] <= key)
		{
			//find the number larger than key from left
			leftIndex++;
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
	int key = partSort(arr, left, right);
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


#define CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<sstream>
#include<string>
#include<vector>
using std::endl;
using std::cout;
using std::cin;

template<class T>
struct ListNode
{
public:
	T _data;
	struct ListNode* _next;
};

template<class T>
class Stack
{
public:
	Stack():_Top(nullptr){}
	
	void push(const T& data)
	{
		if (_Top == nullptr)
		{
			_Top = new ListNode<T>;
			_Top->_data = data;
			_Top->_next = nullptr;
		}
		else
		{
			ListNode<T>* newNode = new ListNode<T>;
			newNode->_next = _Top;
			newNode->_data = data;
			_Top = newNode;
		}
	}

	void pop()
	{
		assert(_Top);
		ListNode<T>* tmp = _Top;
		_Top = _Top->_next;
		delete tmp;
	}

	T& top()
	{
		assert(_Top);
		return _Top->_data;
	}

	bool empty() const
	{
		return _Top == nullptr;
	}

	~Stack()
	{
		while (_Top != nullptr)
		{
			pop();
		}
	}

private:
	ListNode<T>* _Top;
};


float ReversePolishCalc(const std::vector<std::string> token)
{
	Stack<float> st;
	for (int i = 0; i < token.size(); i++)
	{
		int tmp = atof(token[i].c_str());
		if (tmp)
		{
			st.push(tmp);
		}
		else
		{
			float a = 0, b = 0, ret;
			switch (token[i][0])
			{
			case '+':
				a = st.top();
				st.pop();
				b = st.top();
				st.pop();
				ret = b + a;
				st.push(ret);
				break;
			case '-':
				a = st.top();
				st.pop();
				b = st.top();
				st.pop();
				ret = b - a;
				st.push(ret);
				break;
			case '*':
				a = st.top();
				st.pop();
				b = st.top();
				st.pop();
				ret = b * a;
				st.push(ret);
				break;
			case '/':
				a = st.top();
				assert(a!=0);
				st.pop();
				b = st.top();
				st.pop();
				ret = b / a;
				st.push(ret);
				break;
			default:
				throw;
				break;
			}
		}
	}
	return st.top();
}

int main()
{
	std::string str;
	while (getline(cin, str))
	{
		if (strcmp(str.c_str(), "0"))
		{
			break;
		}
		std::stringstream stringstr(str);
		std::vector<std::string> input;
		while (stringstr >> str)
		{
			input.push_back(str);
		}
		cout << ReversePolishCalc(input) << endl;
	}
	return 0;
}

#define CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<string>
using std::endl;
using std::cout;
using std::cin;

template<class T>
struct ListNode
{
public:
	T _data;
	struct ListNode* _next;
};

template<class T>
class Stack
{
public:
	Stack():_Top(nullptr){}
	
	void push(const T& data)
	{
		if (_Top == nullptr)
		{
			_Top = new ListNode<T>;
			_Top->_data = data;
			_Top->_next = nullptr;
		}
		else
		{
			ListNode<T>* newNode = new ListNode<T>;
			newNode->_next = _Top;
			newNode->_data = data;
			_Top = newNode;
		}
	}

	void pop()
	{
		assert(_Top);
		ListNode<T>* tmp = _Top;
		_Top = _Top->_next;
		delete tmp;
	}

	T& top()
	{
		assert(_Top);
		return _Top->_data;
	}

	bool empty() const
	{
		return _Top == nullptr;
	}

	~Stack()
	{
		while (_Top != nullptr)
		{
			pop();
		}
	}

private:
	ListNode<T>* _Top;
};

template<class T>
T ReversePolishCalc(const std::string token)
{
	
}

int main()
{
	int input;
	//cin >> input;
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	while (!st.empty())
	{
		cout << st.top()<<endl;
		st.pop();
	}
	return 0;
}


#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


void InsertionSort(int* arr, const int size)
{
	//left index for sorted array
	int left = 0;
	//right index for sorted array
	int right = size - 1;

	while (right > left)
	{
		//choose the minimum number's index
		int minIndex = left;
		//choose the maximum number's index
		int maxIndex = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (arr[i] > arr[maxIndex])
			{
				maxIndex = i;
			}
			if (arr[i] < arr[minIndex])
			{
				minIndex = i;
			}
		}
		swap(arr[left], arr[minIndex]);
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}
		swap(arr[right], arr[maxIndex]);
		left++;
		right--;
	}
	
}


void selectionSort(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		int smallIndex = i;
		int j = i;
		while (j < size)
		{
			if (arr[smallIndex] > arr[j])
			{
				smallIndex = j;
			}
			++j;
		}
		if (i != smallIndex)
		{
			swap(arr[i], arr[smallIndex]);
		}
	}
}

void InsertionSort(int* arr, const int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i;
		while (j)
		{
			if (key < arr[j-1])
			{
				arr[j] = arr[j-1];
				j--;
			}
			else
			{
				break;
			}
		}
		arr[j] = key;
	}
}

void BubbleSort(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
int main()
{
	int arr[] = { 432,0,56,8,45,2,34,7,-67,-43,23 };
	//BubbleSort(arr, sizeof(arr) / sizeof(int));
	//InsertionSort(arr, sizeof(arr) / sizeof(int));
	selectionSort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}
 #include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


//Create a method that uses a loop to calculate the summation.
int sum(int n)
{
	if (n < 1)
		return 0;
	return sum(n - 1) + n;
}

int sumLoop(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n;
		n--;
	}
	return sum;
}

int main()
{
	int input;
	cout << "please enter a number>:";
	cin >> input;
	cout << sum(input)<<endl;
	cout << sumLoop(input)<<endl;
	
	return 0;
}
#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int binarySearch(int* arr, int size, int key)
{
	int left = 0;
	int right = size - 1;
	while (right >= left)
	{
		int mid = (right + left) / 2;
		if (key == arr[mid])
		{
			return mid;
		}
		else if(key > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;

}

int main()
{
	int arr[] = { -356,-256,-128,-45,-5,-3,7,8,10,21,22 };
	cout << "enter a number you would like to search>:";
	int input;
	cin >> input;
	cout<<binarySearch(arr, sizeof(arr)/sizeof(int), input);
	return 0;
}

#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class ListNode
{
public:
	int _data;
	ListNode* _next;
};

class SortedLinkedList
{
public:
	SortedLinkedList():_head(nullptr){}
	void push(int data)
	{
		if (_head == nullptr)
		{
			_head = new ListNode;
			_head->_data = data;
			_head->_next = nullptr;
			cout << _head->_data;
			cout << endl;
		}
		else
		{
			if (data < _head->_data)
			{
				ListNode* tmp = new ListNode;
				tmp->_data = data;
				tmp->_next = _head;
				_head = tmp;
			}
			else
			{
				ListNode* prev = _head;
				ListNode* next = _head->_next;
				while (next != nullptr)
				{
					if (data > next->_data)
					{
						prev = next;
						next = next->_next;
					}
					else
					{
						break;
					}
				}
				ListNode* tmp = new ListNode;
				tmp->_data = data;
				tmp->_next = next;
				prev->_next = tmp;

			}
			ListNode* cur = _head;
			while (cur != nullptr)
			{
				cout << cur->_data<<" ";
				cur = cur->_next;
			}
			cout << endl;
		}
	}

	~SortedLinkedList()
	{
		while (_head != nullptr)
			{
			ListNode* tmp = _head;
			_head = _head->_next;
			delete tmp;
			}
		
	}

private:
	ListNode* _head;
};

int main()
{
	SortedLinkedList st;
	int input;
	cout << "please enter a number>:";
	cin >> input;
	while (input != -1)
	{
		st.push(input);
		cout << "please enter a number>:";
		cin >> input;
	}
	return 0;
}

#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class ListNode
{
public:
	int _data;
	ListNode* _next;
};

class Queue
{
public:
	Queue():_front(nullptr),_end(nullptr),_count(0)	{		
	}

	void enQueue(int data)
	{
		if (_count == 0)
		{
			_front = _end = new ListNode;
			_front->_data = data;
			_front->_next = nullptr;
		}
		else
		{
			ListNode* tmp = new ListNode;
			tmp->_data = data;
			tmp->_next = nullptr;
			_end->_next = tmp;
			_end = tmp;
		}
		++_count;
	}

	int deQueue()
	{
		if (_count == 0)
		{
			throw;
		}
		int ret = _front->_data;
		ListNode* tmp = _front;
		_front = _front->_next;
		delete tmp;
		--_count;
		return ret;
	}

	bool isEmpty()
	{
		return _count == 0;
	}

	~Queue()
	{
		while (_count != 0)
		{
			ListNode* tmp = _front;
			_front = _front->_next;
			delete tmp;
			--_count;
		}
	}
private:
	ListNode* _front;
	ListNode* _end;
	int _count;
};

int main()
{
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);
	q.enQueue(6);
	while (!q.isEmpty())
	{
		cout << q.deQueue() << endl;
	}
	return 0;
}
#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Queue
{
public:
	Queue() :_count(0), _front(0), _back(0)
	{
		for (int i = 0; i < maxSize; i++)
		{
			_arr[i] = 0;
		}
	}
	void enqueue(int data)
	{
		if (_count == 10)
		{
			throw;
		}
		if (_back == maxSize)
		{
			_back = 0;
		}
		_arr[_back++] = data;
		_count++;
	}
	int dequeue()
	{
		if (_count == 0)
		{
			throw;
		}
		int tmp = _arr[_front];
		++_front;
		if (_front == maxSize)
		{
			_front = 0;
		}
			--_count;
			return tmp;
	}

	bool isEmpty()
	{
		return _count == 0;
	}

private:
	const static int maxSize = 10;
	int _arr[maxSize];
	int _count;
	int _front;
	int _back;
};

int main()
{
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);
	q.enqueue(10);
	for (int i = 0; i < 10; i++)
	{
		cout << q.dequeue()<<endl;
	}
	q.enqueue(11);
	q.enqueue(12);
	q.enqueue(13);
	q.enqueue(14);
	while (!q.isEmpty())
	{
		cout<<q.dequeue() << endl;
	}
	return 0;
}

#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Queue
{
public:
	Queue() :_count(0), _front(0), _back(0)
	{
		for (int i = 0; i < maxSize; i++)
		{
			_arr[i] = 0;
		}
	}
	void enqueue(int data)
	{
		if (_count == 10)
		{
			throw;
		}
		_arr[_back++] = data;
		_count++;
	}
	int dequeue()
	{
		if (_count == 0)
		{
			throw;
		}
		int tmp = _arr[0];
		if (_count == 1)
		{
			--_count;
			return tmp;
		}
		for (int i = 0; i < _count-1; i++)
		{
			_arr[i] = _arr[i + 1];
		}
		_count--;
		return tmp;
	}

private:
	const static int maxSize = 10;
	int _arr[maxSize];
	int _count;
	int _front;
	int _back;
};

int main()
{
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	for (int i = 0; i < 5; i++)
	{
		cout << q.dequeue()<<endl;
	}
	return 0;
}

#define CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	char arr[100];
	cout << "please enter a line of text.>:";
	cin.getline(arr, 100);
	string tmp;
	for (int i = 0; i < sizeof(arr); i++)
	{
		if (arr[i] != ' ' && arr[i] != '\0')
		{
			tmp.push_back(arr[i]);
		}
		else
		{
			if (atoi(tmp.c_str()))
			{
				cout << atof(tmp.c_str()) * 2 << endl;
				tmp.erase();
			}
			else
			{
				cout << tmp << endl;
				tmp.erase();
			}
		}
	}
	return 0;
}
int main()
{
	char arr[100];
	cout << "please enter a line of text.>:";
	cin.getline(arr, 100);
	string tmp;
	for (int i = 0; i < sizeof(arr); i++)
	{
		if (arr[i] != ' ' && arr[i] != '\0')
		{
			tmp.push_back(arr[i]);
		}
		else
		{
			if (atoi(tmp.c_str()))
			{
				cout << atoi(tmp.c_str()) * 2 <<endl;
				tmp.erase();
			}
			else
			{
				cout << tmp << endl;
				tmp.erase();
			}
		}
	}
	return 0;
}

#define CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int search(const int* arr, int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 523,6345,43,56,8,4,3,-3412,-534,52,53,4,6 };
	cout<< search(arr, sizeof(arr), 4);
	return 0;
}


#define CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	int n;
	cout << "please enter the size of array.>:";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "please enter a numbber, or -1 to exit >:";
		int tmp;
		cin >> tmp;
		if (tmp != -1)
		{
			arr[i] = tmp;
		}
		else
		{
			n = i;
			break;
		}

	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}
#include<iostream>
#include<string>
#include<sstream>
#include<queue>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};

template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
	: _d1(d1)
	, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1& _d1;
	const T2& _d2;
};

int main()
{
	Data<double, int> d1;//Data<T1, int>
	Data<int, double> d2;//Data<T1, T2>
	Data<int*, int*> d3;//Data<T1*, T2*>
	Data<int&, int&> d4(1, 2);//Data<T1&, T2&>
	return 0;

}



#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

template<class Type>
Type Max(const Type &a, const Type &b)
{
	cout<<"This is Max<Type>"<<endl;
	return a > b ? a : b;
}

template<>
int Max<int>(const int &a, const int &b)
{
	cout<<"This is Max<int>"<<endl;
	return a > b ? a : b;
}

template<>
char Max<char>(const char &a, const char &b)
{
	cout<<"This is Max<char>"<<endl;
	return a > b ? a : b;
}

int Max(const int &a, const int &b)
{
	cout<<"This is Max"<<endl;
	return a > b ? a : b;
}

int main()
{
	Max(10,20);//This is Max
	Max(12.34,23.45);//This is Max<Type>
	Max('A','B');//This is Max<char>
	Max<int>(20,30);//This is Max<int>
	return 0;
}


#include<iostream>
#include<string>
#include<sstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	stringstream s;
	int a = 1530757313;
	string ss;
	// 将一个整形变量转化为字符串，存储到string类对象中
	int b;
	s<<a;
	s >> b;
	//多次转换时，必须使用clear将上次转换状态清空掉
	s.clear();
	//不清空会转化失败
	s << b;
	s >> ss;
	cout << b << endl << ss<<endl;
	string sss;
	s.str("");
	s.clear();
	s << ss;
	//多次数据类型转化时，一定要用clear()来清空，才能正确转化，但clear()不会将stringstream底层的string对象清空。
	//可以使用s. str("")方法将底层string对象设置为""空字符串。
	sss = s.str();
	cout << sss << endl<< s.str()<<endl;
	s.str("");
	s.clear();
	s << "hello " << "I am" << " groot\n";
	cout << s.str();
	return 0;
}

#include<iostream>
#include<string>
#include<sstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	stringstream s;
	int a = 1530757313;
	string ss;
	// 将一个整形变量转化为字符串，存储到string类对象中
	int b;
	s<<a;
	s >> b;
	//多次转换时，必须使用clear将上次转换状态清空掉
	s.clear();
	//不清空会转化失败
	s << b;
	s >> ss;
	cout << b << endl << ss<<endl;
	string sss;
	s.str("");
	s.clear();
	s << ss;
	//多次数据类型转化时，一定要用clear()来清空，才能正确转化，但clear()不会将stringstream底层的string对象清空。
	//可以使用s. str("")方法将底层string对象设置为""空字符串。
	sss = s.str();
	cout << sss << endl<< s.str()<<endl;
	s.str("");
	s.clear();
	s << "hello " << "I am" << " groot\n";
	cout << s.str();
	return 0;
}

#include<iostream>
#include<string>
#include<fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
struct ServerInfo
{
	char _ip[32];//地址
	int _port;//端口
};

class ConfigManager
{
public:
	ConfigManager(const char* file = "test.config") :_configFile(file){}
	void WriteBin(const ServerInfo& Info)
	{
		ofstream f(_configFile, ofstream::out | ofstream::binary);
		f.write((const char*) &Info, sizeof(ServerInfo));
		f.close();
	}
	void ReadBin(const ServerInfo& Info)
	{
		ifstream f(_configFile, ifstream::in | ifstream::binary);
		f.read((char*)&Info, sizeof(ServerInfo));
		f.close();
	}
	void WriteTxt(const ServerInfo& Info)
	{
		ofstream f(_configFile);
		f << Info._ip << "\n" << Info._port << "\n";
		f.close();
	}
	void ReadTxt(ServerInfo& Info)
	{
		ifstream ifs(_configFile);
		ifs >> Info._ip >> Info._port;
		ifs.close();
	}
private:
	string _configFile;//配置文件
};

int main()
{
	ServerInfo s1 = { "192.168.1.1", 20};
	ServerInfo s2;
	//ConfigManager().WriteBin(s1);
	//ConfigManager().ReadBin(s2);
	ConfigManager writeTxt("config.txt");
	writeTxt.WriteTxt(s1);
	writeTxt.ReadTxt(s2);
	cout << s2._ip << " " << s2._port << endl;
	return 0;
}

#include<iostream>
#define CRT_SECURE_NO_WARNINGS
using namespace std;

template<class T1, class T2>
class Test
{
public:
	Test() {
		cout << "Test<T1, T2>\n";
	}
private:
	T1 t1;
	T2 t2;
};

//模板的全特化处理
template<>
class Test<int, int>
{
public:
	Test() {
		cout << "Test<int, int>\n";
	}
private:
	int t1;
	int t2;
};

//模板的偏特化处理
template<class T1>
class Test<T1, int>
{
public:
	Test() {
		cout << "Test<T1, int>\n";
	}
private:
	T1 t1;
	int t2;

};

template<class T1>
class Test<int, T1>
{
public:
	Test() {
		cout << "Test<int, T1>\n";
	}
private:
	T1 t1;
	int t2;

};

int main()
{

	//实例化对象的时候会和最匹配的进行匹配
	Test<char, char> t1;//Test<T1, T2>
	Test<char, int> t2;//Test<T1, int>
	Test<int, char> t3;//Test<int, T1>
	Test<int, int> t4;//Test<int, int>
	return 0;
}


#include<iostream>
#define CRT_SECURE_NO_WARNINGS
using namespace std;

//非类型模板参数，作为常数使用，只能给整形，必须在初始化时赋值
template<class T, size_t N = 5>
class Test
{
public:
	void test()
	{
		cout << sizeof(arr) << endl;
	}

private:
	T arr[N];
};

int main()
{
	Test<int> t1;
	t1.test();
}

#include<iostream>
#define CRT_SECURE_NO_WARNINGS
using namespace std;

//模板分类，
//函数模板，例：
template<class T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//类模板
template<class T>
class Test {

};


//模板的特化，对模板的特殊化处理
template<class T>
bool IsEqual(const T& a, const T& b)
{
	return a == b;
}

bool IsEqual(const char*& a, const char*& b)
{
	return strcmp(a, b) == 0 ? true : false;
}

bool IsEqual(char* a, char* b)
{
	return strcmp(a, b) == 0 ? true: false;
}

int main()
{
	int a = 1;
	int b = 1;
	std::cout << "a and b are " << IsEqual(a,b) << std::endl;
	char arr1[] = "hello";
	char arr2[] = "hello";
	std::cout << "a and b are " << IsEqual(arr1, arr2) << std::endl;
	const char* str1 = "hello";
	const char* str2 = "hello";
	std::cout << "a and b are " << IsEqual(str1, str2) << std::endl;
	return 0;
}
 
#include<iostream>
#define CRT_SECURE_NO_WARNINGS
using namespace std;

//用于静态开辟类型数组
//string或double会报错
//非类型模板参数，只能给int
template<class T, int N = 10>
class Array
{
private:
	T arr[N];
};

int main()
{
	Array<int> a1;
	Array<char, 30> a2;
	return 0;
}

int main()

{

priority_queue<int> a;

priority_queue<int, vector<int>, greater<int> > c;

priority_queue<string> b;

for (int i = 0; i < 5; i++)

{

a.push(i);

c.push(i);

}

while (!a.empty())

{

cout << a.top() << ' ';

a.pop();

}

cout << endl;

while (!c.empty())

{

cout << c.top() << ' ';

c.pop();

}

cout << endl;

b.push("abc");

b.push("abcd");

b.push("cbd");

while (!b.empty())

{

cout << b.top() << ' ';

b.pop();

}

cout << endl;

return 0;

}


char* retString()
{
	static char arr[20] = "abcd\n";
	return arr;
}

int main()
{
	char* ret = retString();
	cout << ret;
	return 0;
}

//双向队列,底层组成类似动态开辟二维数组
//适合头尾操作，不适合中间操作
dequeue<int> dq;
#define CRT_SECURE_NO_WARNINGS
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> st;
        int j = 0;
        int i = 0;
        for (i; i < pushV.size(); i++)
        {
            st.push(pushV[i]);
            while ((!st.empty()) && (popV[j] == st.top()))
            {
                st.pop();
                j++;
            }
        }
        if (j == (popV.size() - 1))
            return true;
        else
            return false;

    }
};
int main()
{
    vector<int> v1 = { 1,2,3,4,5 };
    vector<int> v2 = { 4,5,3,2,1 };
    cout<<Solution().IsPopOrder(v1, v2);
    int* arr[20] = { 0 };
    int* (*ptr)[20] = &arr;
    return 0;
}
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min.empty())
        {
            min.push(val);
        }
        else
        {
            if(min.top() >= st.top())
            {
                min.push(val);
            }
        }
    }
    
    void pop() {
        if(st.top() == min.top())
        {
            min.pop();
        }
        st.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
    stack<int> st;
    stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
        int j = 0;
        int i = 0;
        for(i; i < pushV.size();i++)
        {
            st.push(pushV[i]);
            while((!st.empty()) && (popV[j] == st.top()))
            {
                st.pop();
                j++;
            }
        }
        if(j == popV.size())
            return true;
        else
            return false;
        
    }
};

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty())
        {
            while(!s1.empty())
            {
            s2.push(s1.top());
            s1.pop();                
            }
        }
        int tmp = s2.top();
        s2.pop();
        return tmp;
    }
    
    int peek() {
        if(s2.empty())
        {
            while(!s1.empty())
            {
            s2.push(s1.top());
            s1.pop();                
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
    }
    private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
class MyStack {
public:
    MyStack() 
    {
    }
    
    void push(int x) {
        if(q1.empty())
        {
            q2.push(x);
        }
        else
        {
            q1.push(x);
        }
    }
    
    int pop() {
        int tmp;
        if(q1.empty())
        {
            while(q2.size() != 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            tmp = q2.front();
            q2.pop();
        }
        else
        {
            while(q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            tmp = q1.front();
            q1.pop();
            
        }
        return tmp;
    }
    
    int top() {
        if(q1.empty())
        {
            return q2.back();
        }
        else
        {
            return q1.back();
        }
    }
    
    bool empty() {
        return q1.empty()&&q2.empty();
    }
    private:
            queue<int> q1;
        queue<int> q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
  template<class T, class Con = deque<T>>

  class queue

  {

  public:

    queue();

    void push(const T& x);

    void pop();

    T& back();

    const T& back()const;

    T& front();

    const T& front()const;

    size_t size()const;

    bool empty()const;

  private:

    Con _c;

  };

};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue q(nums.begin(), nums.begin()+k,greater<int>());
        for(int i = k; i<nums.size();i++)
        {
            if(nums[i] > q.top())
            {
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
        }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue q(nums.begin(), nums.end());
        for(int i = 1; i<k;i++)
        {
            q.pop();
        }
        return q.top();
        }
};


class Solution {

public:

int findKthLargest(vector<int>& nums, int k) {

sort(nums.begin(),nums.end());

return nums[nums.size()-k];

}

};

queue.push(tree.root )

while(true)

node = queue.pop()

output(node.value)//输出节点对应数字

if(null==node)

break

for(child_node in node.children)

queue.push(child_node)


void main()

{

queue<char> Q;

char x,y;

x='n';y='g';

Q.push(x);Q.push('i');Q.push(y);

Q.pop();Q.push('r');Q.push('t');Q.push(x);

Q.pop();Q.push('s');

while(!Q.empty())

{

x = Q.front();

Q.pop();

cout<<x;

};

cout<<y;

}


void main()

{

stack<char> S;

char x,y;

x='n';y='g';

S.push(x);S.push('i');S.push(y);

S.pop();S.push('r');S.push('t');S.push(x);

S.pop();S.push('s');

while(!S.empty())

{

x = S.top();

S.pop();

cout<<x;

};

cout<<y;

}



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};
void main()

{

queue<char> Q;

char x,y;

x='n';y='g';

Q.push(x);Q.push('i');Q.push(y);

Q.pop();Q.push('r');Q.push('t');Q.push(x);

Q.pop();Q.push('s');

while(!Q.empty())

{

x = Q.front();

Q.pop();

cout<<x;

};

cout<<y;

}



void main()

{

stack<char> S;

char x,y;

x='n';y='g';

S.push(x);S.push('i');S.push(y);

S.pop();S.push('r');S.push('t');S.push(x);

S.pop();S.push('s');

while(!S.empty())

{

x = S.top();

S.pop();

cout<<x;

};

cout<<y;

}


class Solution {
public:
    
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0;i<tokens.size();i++)
        {
            switch(tokens[i].back())
            {
                case '+':
                    {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();
                    st.push(num1 + num2);
                    break;                        
                    }
                case '-':
                    {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();
                    st.push(num2 - num1);
                    break;
                    }
                case '*':
                    {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();
                    st.push(num1 * num2);
                    break;
                    }
                
                case '/':
                    
              {
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.pop();
                    st.push(num2 / num1);
                    break;
                
                }
                default:
                st.push(stoi(tokens[i]));
                break;
            }
        }
        return st.top();
        
    }
};
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minVal.empty())
        {
            minVal.push_back(val);
        }
        else
        {
            if(st.top() <= minVal[minVal.size()-1])
            {
                minVal.push_back(val);
            }
        }
    }
    
    void pop() {
        if(minVal[minVal.size()-1] == st.top())
        {
            minVal.pop_back();
            st.pop();
        }
        else
        {
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minVal[minVal.size()-1];
    }
private:    
    stack<int> st;
    vector<int> minVal;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
template<typename T>

void removeDuplicates(list<T> &aList)

{

T curValue;

list<T>::iterator cur, p;

cur = aList.begin();

while (cur != aList.end())

{

curValue = *cur;

p=++cur;

while (p != aList.end())

{

if (*p == curValue)

{

 p == cur ? cur = p = aList.erase(p) : p = aList.erase(p);
}

else

{

p++;

}

}

}

}



int main()

{

int array[] = { 1, 2, 3, 4, 0, 5, 6, 7, 8, 9 };

int n = sizeof(array) / sizeof(int);

list<int> mylist(array, array+n);

auto it = mylist.begin();

while (it != mylist.end())

{

if(* it != 0)

cout<<* it<<" ";

else

it = mylist.erase(it);

++it;

}

return 0;

}


int main()

{

int ar[] = { 0,1, 2, 3, 4, 5, 6, 7, 8, 9 };

int n = sizeof(ar) / sizeof(int);

list<int> mylist(ar, ar+n);

list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);

reverse(mylist.begin(), pos);

reverse(pos, mylist.end());

list<int>::const_reverse_iterator crit = mylist.crbegin();

while(crit != mylist.crend())

{

cout<<*crit<<" ";

++crit;

}

cout<<endl;

}


string arr[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };


class Solution {
public:
	void _letterCombination(string digits, int i, string s, vector<string>& ret)
	{
		if (digits[i] == '\0')
		{
			ret.push_back(s);
		}
		else
		{
			int num = digits[i] - '0';
			const string& str = arr[num];
			for (int j = 0; j < str.size(); j++)
			{
				char c = str[j];
				_letterCombination(digits, i + 1, s+c, ret);
			}
		}
	}
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
        {
            return vector<string>();
        }
		vector<string> ret;
		int i = 0;
		string s;
		_letterCombination(digits, i, s, ret);
		return ret;
    }
};

class Solution {
public:
    
    vector<string> findLetters(const char& c)
    {
	vector<string> ret;
	switch (c)
	{
	case '2':
		ret.push_back("a");
		ret.push_back("b");
		ret.push_back("c");
		break;
	case '3':
		ret.push_back("d");
		ret.push_back("e");
		ret.push_back("f");
		break;
	case '4':
		ret.push_back("g");
		ret.push_back("h");
		ret.push_back("i");
		break;
	case '5':
		ret.push_back("j");
		ret.push_back("k");
		ret.push_back("l");
		break;
	case '6':
		ret.push_back("m");
		ret.push_back("n");
		ret.push_back("o");
		break;
	case '7':
		ret.push_back("p");
		ret.push_back("q");
		ret.push_back("r");
		ret.push_back("s");
		break;
	case '8':
		ret.push_back("t");
		ret.push_back("u");
		ret.push_back("v");
		break;
	case '9':
		ret.push_back("w");
		ret.push_back("x");
		ret.push_back("y");
		ret.push_back("z");
		break;
	}
	return ret;
    }
    
    vector<string> calc(vector<string> a, vector<string> b)
    {
	vector<string> ret;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			string c = a[i];
			c += b[j];
			ret.push_back(c);
		}
	}
	return ret;
    }
    vector<string> letterCombinations(string digits) {
    if(digits.size() == 0)
    {
        return vector<string>();
    }
	vector<string> tmp2 = findLetters(digits[digits.size()-1]);
    for (int i = digits.size() - 2; i >=0; i--)
	{
		vector<string> tmp = findLetters(digits[i]);
		vector<string> ret = calc(tmp, tmp2);
		tmp2 = ret;
	}
    return tmp2;
        
    }
};

#include<iostream>
#define CRT_SECURE_NO_WARNINGS
using namespace std;
#include<string>
#include<vector>

vector<string> findLetters(const char& c)
{
	vector<string> ret;
	switch (c)
	{
	case '2':
		ret.push_back("a");
		ret.push_back("b");
		ret.push_back("c");
		break;
	case '3':
		ret.push_back("d");
		ret.push_back("e");
		ret.push_back("f");
		break;
	case '4':
		ret.push_back("g");
		ret.push_back("h");
		ret.push_back("i");
		break;
	case '5':
		ret.push_back("j");
		ret.push_back("k");
		ret.push_back("l");
		break;
	case '6':
		ret.push_back("m");
		ret.push_back("n");
		ret.push_back("o");
		break;
	case '7':
		ret.push_back("p");
		ret.push_back("q");
		ret.push_back("r");
		ret.push_back("s");
		break;
	case '8':
		ret.push_back("t");
		ret.push_back("u");
		ret.push_back("v");
		break;
	case '9':
		ret.push_back("w");
		ret.push_back("x");
		ret.push_back("y");
		ret.push_back("z");
		break;
	}
	return ret;
}

vector<string> calc(vector<string> a, vector<string> b)
{
	vector<string> ret;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			string c = a[i];
			c += b[j];
			ret.push_back(c);
		}
	}
	return ret;
}

int main()
{
	string input = "234";
	vector<string> tmp2 = findLetters(input[input.size()-1]);
	for (int i = input.size() - 2; i >=0; i--)
	{
		vector<string> tmp = findLetters(input[i]);
		vector<string> ret = calc(tmp, tmp2);
		tmp2 = ret;
	}

	for (auto e : tmp2)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;

}


class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int halfSize = numbers.size() / 2;
        
        sort(numbers.begin(), numbers.end());            
        int tmp = numbers[0];
        int count = 1;
        for(int i = 1; i < numbers.size(); i++)
        {
            if(numbers[i] == tmp)
            {
                count++;
            }
            else
            {
                if(count > halfSize)
                {
                    return tmp;
                }
                count = 1;
                tmp = numbers[i];
            }
        }
        return tmp;
    }
};

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int halfSize = numbers.size() / 2;
        sort(numbers.begin(), numbers.end());
        for(int i = 0; i < numbers.size(); i++)
        {
            int count = 0;
              int tmp = numbers[i];
            for(int j = 1; j < numbers.size(); j++)
            {
                if(tmp == numbers[j])
                {
                    count++;
                }
                if(count > halfSize)
                {
                    return tmp;
                }
            }
        }
        return numbers[0];
    }
};
class Solution 

{

public:

  int FindGreatestSumOfSubArray(vector<int> array) 

{

    int cursum=array[0];

    int maxsum=array[0];

    for(int i=1;i<array.size();i++)

{

      cursum+=array[i];

      if(cursum<array[i])

        cursum=array[i];

      if(cursum>maxsum)

        maxsum=cursum;       

    }

return maxsum;

  }

};
class Solution {

public:

  int max(const int& x,const int& y)

  {

    int max = x;

    if(y > x)

      max = y;

    return max;

  }

  int FindGreatestSumOfSubArray(vector<int> array) {

    int maxNum = array[array.size() - 1];

    for(int i = 0; i < array.size(); i++)

    {

      int sum = array[i];

      maxNum = max(sum, maxNum);

      int j = i+1;

      while(j < array.size())

      {

        sum += array[j];

        maxNum = max(sum, maxNum);

        j++;

      }

    }

    return maxNum;

  }

};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int key = 0;
        for(int i = 0; i< nums.size(); i++)
        {
            key ^= nums[i];
        }
        int q = 0;
        while(((key >> q) & 1) != 1)
        {
            q++;
        }
        vector<int> arr1;
        vector<int> arr2;
        for(int i = 0; i< nums.size(); i++)
        {
            if(((nums[i] >> q) & 1) == 1)
            {
                arr1.push_back(nums[i]);
            }
            else
            {
                arr2.push_back(nums[i]);
            }
        }
        int ans = 0;
        vector<int> ret;
        for(int i = 0; i< arr1.size(); i++)
        {
            ans ^= arr1[i];
        }
        ret.push_back(ans);
        ans = 0;
        for(int i = 0; i< arr2.size(); i++)
        {
            ans ^= arr2[i];
        }
        ret.push_back(ans);
        return ret;        
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size();i += 3)
        {
            if(i == nums.size() - 1)
            {
                return nums[i];
            }
            else if(nums[i] != nums[i+1])
            {
                return nums[i];
            }
        }
        return 0;
    }
};

//只解决正数 不解决负数
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        int flag = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        int remainder = sum % 3;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 3 == remainder)
            {
                flag = 0;
                for(int j = 0; j < nums.size(); j++)
                {
                    if(nums[j] == nums[i] && i != j)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    return nums[i];
                }
            }
        }
        return nums.size() -1;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        while(j < nums.size())
        {
            if(nums[i] != nums[j])
            {
                nums[i+1] = nums[j];
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return i+1;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator slow = nums.begin();
        vector<int>::iterator fast = nums.begin()+1;
        while(fast != nums.end())
        {
            if(*fast == *slow)
            {
                fast = nums.erase(fast);
            }
            else
            {
                slow++;
                fast++;
            }
        }
        return slow - nums.begin() + 1;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        ret.resize(numRows);
        for(int i = 0; i < ret.size(); i++)
        {
            ret[i].resize(i+1);
            ret[i][0] = 1;
            ret[i][ret[i].size() - 1] = 1;
            for(int j = 1; j < ret[i].size() - 1; j++)
            {
                ret[i][j] = ret[i-1][j] + ret[i-1][j-1];
            }
        }
        return ret;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(auto e: nums)
        {
            ret ^= e;
        }
        return ret;
    }
};
class Solution {
public:

    void reverse(string& s, int left, int right)
    {
        while (right > left)
        {
            swap(s[left], s[right]);
            right--;
            left++;
        }
    }

    string addStrings(string num1, string num2) {
        string retstr;
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int carry = 0;
        while (end1 >= 0 || end2 >= 0)
        {
            int temp1 = 0, temp2 = 0, ttl = 0;
            if (end1 >= 0)
                temp1 = num1[end1] - '0';
            if (end2 >= 0)
                temp2 = num2[end2] - '0';
            ttl = temp1 + temp2 + carry;
            if (ttl > 9)
            {
                carry = 1;
                ttl -= 10;
            }
            else
            {
                carry = 0;
            }
            retstr += (ttl + '0');
            end1--;
            end2--;
        }
        if (carry == 1)
        {
            retstr += '1';
        }
        int start = 0;
        int end = retstr.size() - 1;
        while (start < end)
        {
            swap(retstr[start], retstr[end]);
            start++;
            end--;
        }
        return retstr;

    }

    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0')
        {
            string s("0");
            return s;
        }
        int end1 = num1.size() - 1;
        string ttlstr;
        int carry = 0;
        int sign = 0;
        for (end1; end1 >= 0; end1--)
        {
            string tmpstr;
            for (int j = sign; j > 0; j--)
            {
                tmpstr += '0';
            }
            for (int i = num2.size() - 1; i >= 0; i--)
            {
                int temp1 = num1[end1] - '0';
                int temp2 = num2[i] - '0';
                int product = temp1 * temp2 + carry;
                if (product > 9)
                {
                    carry = product / 10;
                    product %= 10;
                }
                else
                {
                    carry = 0;
                }
                tmpstr += (product + '0');
            }
            if (carry != 0)
            {
                tmpstr += (carry + '0');
                carry = 0;
            }
            reverse(tmpstr, 0, tmpstr.size()-1);
            ttlstr = addStrings(tmpstr, ttlstr);
            sign += 1;
        }
        return ttlstr;
    }
};


class Solution {
public:
    void reverse(string& s, int left, int right)
    {
        while(left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    
    string reverseStr(string s, int k) {
        int prev = 0;
        int cur = k-1;
        while(cur < s.size())
        {
            reverse(s, prev, cur);
            prev+=(2*k);
            cur+=(2*k);
        }
        if(prev < s.size())
        {
            reverse(s, prev, s.size()-1);
        }
        return s;
    }
};

class Solution {
public:
    bool isSameLetter(char a, char b)
    {
        if( 'A' <= a && a <= 'Z')
        {
            a = a - 'A' + 'a';
        }
        if( 'A' <= b && b <= 'Z')
        {
            b = b - 'A' + 'a';
        }
        if(a == b)
            return true;
        else
            return false;
    }
    bool isLetter(char x)
    {
        return ((x >='a' && x <='z') || (x>='A' && x<='Z')|| (x>='0' && x<='9'));
    }
    
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right)
        {
            while(left < right && !isLetter(s[left]))
            {
                left ++;
            }
            while(left < right && !isLetter(s[right]))
            {
                right--;
            }
        
            if(left == right)
            {
                return true;
            }
            if(isSameLetter(s[left], s[right]))
            {
                left++;
                right--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    string addStrings(string num1, string num2) {
        string retstr;
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int carry = 0;
        while(end1 >= 0 || end2 >=0)
        {
            int temp1 = 0, temp2 = 0, ttl = 0; 
            if(end1 >= 0)
                temp1 = num1[end1] - '0';
            if(end2 >= 0)
                temp2 = num2[end2] - '0';
            ttl = temp1 + temp2 + carry;
            if(ttl > 9)
            {
                carry = 1;
                ttl -= 10;
            }
            else
            {
                carry = 0;
            }
            retstr += (ttl + '0');
            end1--;
            end2--;
        }
        if(carry == 1)
        {
            retstr+='1';
        }
        int start = 0;
        int end = retstr.size() - 1;
        while(start < end)
        {
            swap(retstr[start], retstr[end]);
            start++;
            end--;
        }
        return retstr;
        
    }
    
};

class Solution {
public:
    int StrToInt(string str) {
        int sum = 0;
        int temp = 1;
        int end = str.size() - 1;
        while(end > 0)
        {
            if(str[end] - '0' < 10)
            {
                sum += ((str[end] - '0') * temp);
                temp *= 10;
            }
            else
            {
                return 0;
            }
            end--;
        }
        if(str[0] == '+')
        {
            return sum;
        }
        else if(str[0] == '-')
        {
            return sum *= (-1);
        }
        else if ( str[0] >='0' && str[0] <= '9')
        {
           return sum += ((str[end] - '0') * temp);
        }
        else
        {
            return 0;   
        }
    }
};

class Solution {

public:

  int firstUniqChar(string s) {

     

  int temp[26] = {0};

  for(int i = 0; i< s.size(); i++)

  {

    temp[s[i]-'a']++;

  }

  for(int i = 0; i < s.size(); i++)

  {

    if(temp[s[i]-'a'] == 1)

    {

      return i;

    }

  }

  return -1;

  }

};
class Solution {
public:
    int firstUniqChar(string s) {
        
    for(int i=0; i<s.size(); ++i)

    {

      int index = s.find(s[i]);

      int reverse_index = s.rfind(s[i]);  

      if(index == reverse_index)

        return i;

    }

    return -1;
    }
};

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int cur = s.size() - 1;
    while (cur && s[cur] != ' ')
    {
        cur--;
    }
    if (cur)
    {
        string temp = s.substr(cur + 1, s.size() - cur + 1);
        cout << temp.size();
    }
    else
    {
        cout << s.size();
    }
    return 0;
}
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = 0;
    string::iterator it = s.begin();
    int a[127] = {0};
    while(it != s.end())
    {
        a[*it]++;
        it++;
    }
    it = s.begin();
    while(it != s.end())
    {
        if(a[*it] == 1)
        {
            cout<<*it;        
            return 0;
        }
        it++;
        
    }
    
    cout<< -1;
    return 0;
}
#define _crt_secure_no_warnings
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;


int main(int argc, char* argv[])

{

	string strText = "How are you?";

	string strSeparator = " ";

	string strResult;

	int size_pos = 0;

	int size_prev_pos = 0;
	//size_pos = 7
	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
	{
		// How are 
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
		//How are 
		cout << strResult << " ";
		//size prev pos = 8
		size_prev_pos = ++size_pos;

	}
	//8  
	if (size_prev_pos != strText.size())

	{
		//you? 
		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

	}

	cout << endl;

	return 0;

}

int main()

{

string str("Hello Bit.");

str.reserve(111);

str.resize(5);

str.reserve(50);

cout<<str.size()<<":"<<str.capacity()<<endl;

return 0;

}

int main(int argc, char* argv[])

{

	string a = "hello world";

	string b = a;

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;

	string c = b;

	c = "";

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;

	a = "";

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;

	return 0;

}
int main()
{
	//三种最常用的构造函数
	std::string s1 = "hello world";
	std::string s2(s1);
	std::string s3 = s1;
	//三种遍历方式
	//s1.operator[](int pos)
	for (int i = 0; i < s1.size(); i++)
	{
		std::cout << s1[i] << " ";
	}
	std::cout << std::endl;
	//iterator begin()迭代器遍历
	std::string::iterator it = s1.begin();
	while (it != s1.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	//auto遍历，语法是auto 变量名 : 字符串名， 将字符串的内容一个个赋给变量
	for (auto e : s1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	s1 += '!';
	std::cout << s1 << std::endl;
	s1 += "!!";
	std::cout << s1 << std::endl;
	s1 += s2;
	std::cout << s1 << std::endl;
	s1.erase(0, 1);
	std::cout << s1 << std::endl;
	s1.push_back('~');
	std::cout << s1 << std::endl;
	s1.append("12345");
	std::cout << s1 << std::endl;
	std::cout<< s1.front();
	std::cout<< s1.back();
}


void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

template <class T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10, b = 20;
	//这里会直接调用上面的因为编译器有了Swap(int, int)的就不用调用模板去推类型了
	Swap(a, b);
	double c = 3.3, d = 4.4;
	Swap(c, d);
	//这里要推测类型所以会调用模板函数
	Swap<int>(a, b);
	//这里因为指定了类型模板所以会调用模板函数
	return 0;
}

#define _crt_secure_no_warnings
#include<iostream>
#include<assert.h>

class A
{
public:
	A();
	~A();
};

A::A()
{
	std::cout << "constructor A\n";
}

A::~A()
{
	std::cout << "destructor A\n";
}

int main()
{
	//一个new调用operator new 先，然后调用里面的constructor
	A* p = (A*)operator new(sizeof(A));
	//这里调用了operator new, 相当于malloc
	//但是没有调用constructor
	//然后这里的new(变量名)类型名(参数)   再调用constructor   
	new(p)A;
	//注意constructor不能直接调用
	//也就是等同于 new p

	//但是destructor可以直接调用
	p->~A();
	operator delete(p);
	//等同于 delete p
	return 0;
}

#include<iostream>
#include<assert.h>
class Date
{
public:
	// 获取某年某月的天数
	inline int GetMonthDay(int year, int month);
	inline int GetYearDay(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return 366;
		}
		else
		{
			return 365;
		}
	}

	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1);

	// 拷贝构造函数

  // d2(d1)
	Date(const Date& d);

	// 赋值运算符重载

  // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d);

	// 析构函数
	~Date();

	// 日期+=天数
	Date& operator+=(int day);

	// 日期+天数
	Date operator+(int day);

	// 日期-天数
	Date operator-(int day);

	// 日期-=天数
	Date& operator-=(int day);

	// 前置++
	Date& operator++();

	// 后置++
	Date operator++(int);

	// 后置--
	Date operator--(int);

	// 前置--
	Date& operator--();

	// >运算符重载
	bool operator>(const Date& d);

	// ==运算符重载
	bool operator==(const Date& d);

	// >=运算符重载
	bool operator >= (const Date& d);

	// <运算符重载
	bool operator < (const Date& d);

	// <=运算符重载
	bool operator <= (const Date& d);

	// !=运算符重载
	bool operator != (const Date& d);

	// 日期-日期 返回天数
	int operator-(const Date& d);

	friend std::ostream& operator<<(std::ostream& os, const Date& d);

private:
	int _year;
	int _month;
	int _day;
};
inline int Date::GetMonthDay(int year, int month)
{

	//设一个数组，给第一个置空，这样每个数组的下标都会对应当月的天数
	//设数组为static，因为频繁调用每次都创建销毁影响性能，static生命周期延长
	static int arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int day = arr[month];
	//检查2月是否为闰年
	if (month == 2)
	{
		//如果是闰年就是29天
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			day = 29;
		}
	}
	return day;
}

// 全缺省的构造函数
Date::Date(int year, int month, int day)
{
		_year = year;
		_month = month;
		_day = day;
	
}

// 拷贝构造函数

// d2(d1)
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

// 赋值运算符重载

// d2 = d3 -> d2.operator=(&d2, d3)
Date& Date::operator=(const Date& d)
{
	//检查是否自己赋值给自己
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//因为退出函数时，对象不会销毁
	//返回*this指针，以便连续赋值
	return *this;
}

// 析构函数
Date::~Date()
{
	//这里完成函数清理工作，由于这个函数没有需要清理的故不写析构函数也没有问题
	;
}

// 日期+=天数
Date& Date::operator+=(int day)
{
	//检查日期是为正数
	if (day >= 0)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
	}
	//如果为负数那就走-=
	else
	{
		*this -= abs(day);
	}
	return *this;
}

// 日期+天数
Date Date::operator+(int day)
{
	Date temp = *this;
	temp += day;
	return temp;
}

// 日期-天数
Date Date::operator-(int day)
{
	Date temp = *this;
	temp -= day;
	return temp;
}

// 日期-=天数
Date& Date::operator-=(int day)
{
	//检查天数是否是正数
	if (day >= 0)
	{
		_day -= day;
		while (_day <= 0)
		{
			_month--;
			_day += GetMonthDay(_year, _month);
			if (_month <= 0)
			{
				_year--;
				_month = 12;
			}
		}
	}
	//如果为负数那就走+=
	else
	{
		*this += abs(day);
	}
	return *this;
}

// 前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// 后置++
Date Date::operator++(int)
{
	Date temp = *this;
	*this += 1;
	return temp;
}

// 后置--
Date Date::operator--(int)
{
	Date temp = *this;
	*this -= 1;
	return temp;
}

// 前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// >运算符重载
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year < d._year)
	{
		return false;
	}
	else
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month < d._month)
		{
			return false;
		}
		else
		{
			if(_day > d._day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	
}

// ==运算符重载
bool Date::operator==(const Date& d)
{
	if (_year == d._year && _month == d._month && _day == d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// >=运算符重载
bool Date::operator >= (const Date& d)
{
	return *this > d || *this == d;
}

// <运算符重载
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}

// <=运算符重载
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}

// !=运算符重载
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

// 日期-日期 返回天数
// size_t Date::operator-(const Date& d)
// {
// 	size_t countDay1 = 0;
// 	size_t countDay2 = 0;
// 	for (int i = 1; i < _year; i++)
// 	{
// 		countDay1 += GetYearDay(i);
// 	}
// 	for (int i = 1; i < _month; i++)
// 	{
// 		countDay1 += GetMonthDay(_year, i);
// 	}
// 	countDay1 += _day;
// 	for (int i = 1; i < d._year; i++)
// 	{
// 		countDay2 += GetYearDay(i);
// 	}
// 	for (int i = 1; i < d._month; i++)
// 	{
// 		countDay2 += GetMonthDay(d._year, i);
// 	}
// 	countDay2 += d._day;
// 	return countDay1 - countDay2;
// }
// 日期-日期 返回天数
int Date::operator-(const Date& d)
{
	Date min = *this;
	Date max = d;
	int flag = 1;
	if (min > max)
	{
		min = d;
		max = *this;
		flag = -1;
	}
	int day = 0;
	while (min != max)
	{
		min++;
		day++;
	}
	
	return day * flag;
}

std::ostream& operator<<(std::ostream& os,const Date& d)
{
    os << d._year << "-" ;
    if(d._month < 10)
	os << "0" << d._month << "-";
    else
        os<<d._month<<"-";
    if(d._day < 10)
        os << "0" <<d._day<<std::endl;
    else
        os<<d._day<<std::endl;
	return os;
}

int main()
{
    int m;
    int year, month, day, addDate;
    std::cin >> m;
    for(int i = 1 ; i <=m ; i++)
    {
        std::cin >> year >> month >> day >> addDate;
        Date a(year, month, day);
        a += addDate;
        std::cout<<a;
    }
    return 0;
}
#include <iostream>
#define _crt_secure_no_warnings
#include<iostream>

class A
{
public:
	A() { _a++; }
	static int GetA() { return _a; }
private:
	static int _a;//访问没有this指针
	int _b;//访问时候会加上this->
};
int A::_a = 0;

int main()
{
	A a;
	std::cout<< A::GetA();
	return 0;
}
int main()
{
    int temp1, temp2;
    int year1, year2, month1, month2, day1, day2;
    cin>>temp1;
    cin>>temp2;
    year1 = temp1 /10000;
    temp1 = temp1 % 10000;
    month1 = temp1 / 100;
    temp1 = temp1 % 100;
    day1 = temp1;
    year2 = temp2 /10000;
    temp2 = temp2 % 10000;
    month2 = temp2 / 100;
    temp2 = temp2 % 100;
    day2 = temp2;
    
    Date d1(year1, month1, day1), d2(year2, month2, day2);
    cout << (d1 - d2);
    return 0;
}
/*
根据输入的日期，计算是这一年的第几天。
保证年份为4位数且日期合法。
进阶：时间复杂度：O(n)\O(n) ，空间复杂度：O(1)\O(1) */

int main()
{
    int year, month, day, ttlDay;
    std::cin >> year >> month >> day;
    //计算每个月总共天数，数组里按下标算的每个月天数
    int arr[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    ttlDay = arr[month-1] + day;
    if(month > 2 && ((year % 4 == 0 && year % 100 != 0)|| year % 400 == 0))
    ttlDay += 1;
    std::cout<<ttlDay;
    return 0;
}
//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
//
//数据范围： 0 < n \le 2000<n≤200
//进阶： 空间复杂度 O(1)O(1) ，时间复杂度 O(n)O(n)

class Add{
    public:
    Add()
    {
        sum+=i;
        i++;
    }
    static int i;
    static int sum;
};

int Add::i = 1;
int Add::sum = 0;
class Solution {
public:
    int Sum_Solution(int n) {
        Add::i = 1;
        Add::sum = 0;
        Add ret[n];
        return Add::sum;
    }
};
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
	struct Node* cur = head;
    while(cur)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = cur->val;
        newNode->next = cur->next;
        cur->next = newNode;
        cur = newNode->next;
    }
    cur = head;

    while(cur)
    {
        struct Node* copiedNode = cur->next;
        if(cur->random)
        {
            copiedNode->random = cur->random->next;
        }
        else
        {
            copiedNode->random = NULL;
        }
        cur = copiedNode->next;
    }
    
        struct Node* copyHead = NULL, *copyTail = NULL;
        cur = head;
        while(cur)
        {
           struct Node* copy = cur->next;
           struct Node* next = copy->next;
 
            if(copyTail == NULL)
            {
                copyHead = copyTail = copy;
            }
            else
            {   
                copyTail->next = copy;
                copyTail = copy;
            }
 
            cur->next = next;
 
            cur = next;
        }
 
        return copyHead;

}

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        
        if(pHead == NULL || pHead->next == NULL)
            return pHead;
        
        struct ListNode* n0 = NULL;
        struct ListNode* n1 = pHead;
        struct ListNode* n2 = n1->next;
        while(n2 != NULL)
        {
            //如果相邻节点不相同，则不需要删除，更新节点，继续向后遍历
            if(n1->val != n2->val)
            {
                n0 = n1;
                n1 = n2;
                n2 = n2->next;
            }
            else
            {
                //如果相邻节点相同
				//则n2去找第一个不相同的节点
                while(n2 && n2->val == n1->val)
                {
                    n2 = n2->next;
                }
                //重新链接，如果要删除的包括头节点，则更新头节点
                if(n0)
                    n0->next = n2;
                else
                    pHead = n2;
                
                // 删除掉重复的节点
                while(n1 != n2)
                {
                    struct ListNode* next = n1->next;
                    free(n1);
                    n1 = next;
                }
                //更新节点
                n1 = n2;
                if(n2)
                    n2 = n2->next;
            }
        }
        
        return pHead;
    }
};

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        ListNode* fast = A;
        ListNode* slow = A;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* ReversedList = NULL;
        while(slow)
        {
            ListNode* next = slow->next;
            slow->next = ReversedList;
            ReversedList = slow;
            slow = next;
        }
        while(ReversedList)
        {
            if(ReversedList->val != A->val)
            {
                return false;
            }
            else
            {
                ReversedList = ReversedList->next;
                A = A->next;
            }
        }
        return true;
    }
};
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
    ListNode* smallHead = (ListNode*)malloc(sizeof(ListNode));
    ListNode* largeHead = (ListNode*)malloc(sizeof(ListNode));
    ListNode* smallTail = (ListNode*)malloc(sizeof(ListNode));
    ListNode* largeTail = (ListNode*)malloc(sizeof(ListNode));
    smallHead->next = NULL;
    largeHead->next = NULL;
    smallTail = smallHead;
    largeTail = largeHead;
    ListNode* cur = pHead;
    while(cur)
    {
        if(cur->val <x)
        {
            smallTail->next = cur;
            smallTail = smallTail->next;
        }
        else
        {
            largeTail->next = cur;
            largeTail = largeTail->next;
        }
        cur = cur->next;
    }
        smallTail->next = largeHead->next;
        largeTail->next = NULL;
        return smallHead->next;
    }
};

#define _crt_secure_no_warnings
#include<iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* meetPoint = NULL;
    while(fast&&fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            meetPoint = slow;
            break;
        }
    }
    while(meetPoint)
    {  
        if(head == meetPoint)
        {
            break;
        }
        head = head->next;
        meetPoint = meetPoint->next;
    }
    return meetPoint;
}

class Super {
	void print();
	virtual void test() const = 0;
};

class Sub:Super
{
	void test()
	{
		std::cout << "test\n";
	}
};

int main() 
{
	Super* ptr = new Super;
	//只要有一个及以上的虚函数的类就是抽象类，就没办法instantiate
	return 0;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//234. Palindrome Linked List

bool isPalindrome(struct ListNode* head){

    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast&&fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode* tail = NULL;
    struct ListNode* newNode = NULL;
    while(slow)
    {
        newNode = slow;
        slow = slow->next;
        newNode->next = tail;
        tail = newNode;
    }
    while(newNode)
    {
        if(head->val == newNode->val)
        {
            head = head->next;
            newNode = newNode->next;
        }
        else
        {
            return false;
        }
    }
    return true;
   
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;



class Employee
{
public:
	Employee(const char*, const char*);
	~Employee();
	void print() const;
private:
	char* last;
	char* first;

};

Employee::Employee(const char* lastName, const char* firstName)
{
	last = new char[strlen(lastName)+1];
	strcpy(last, lastName);
	first = new char[strlen(firstName)+1];
	strcpy(first, firstName);
	cout << "Employee constructor.\n";
}

Employee::~Employee()
{
	cout << "Employee destructor destruct " << last << " " << first;
	delete[] last;
	delete[] first;
}

void Employee::print() const
{
	cout << first << " " << last;
}

class Worker :public Employee
{
public:
	Worker(const char*, const char*, double hour, double wage);
	double getPay() const;
	void print() const;
	~Worker();
private:
	double hour;
	double wage;
};

Worker::Worker(const char* lastName, const char* firstName, double hour, double wage) 
	:Employee(lastName, firstName)
{
	this->hour = hour;
	this->wage = wage;
}

double Worker::getPay() const
{
	return hour * wage;
}

void Worker::print() const
{
	Employee::print();
	cout << " wage is " << getPay()<<endl;
}

Worker::~Worker()
{
	cout << "Worker destructor.\n";
}

int main()
{
	Worker andrew("Ying", "Andrew", 5, 8.1);
	andrew.print();
	return 0;
}

class Point
{
	friend ostream& operator<<(ostream& os,const Point&);
public:
	int get_x()
	{
		return x;
	}
	int get_y()
	{
		return y;
	}
	Point(int a = 0, int b = 0)
	{
		x = a;
		y = b;
	}
protected:
	int x;
	int y;
};

ostream& operator<<(ostream& os,const Point& p)
{
	os << "[ " << p.x << "," << p.y << " ]\n";
	return os;
}

class Circle : public Point
{
	friend ostream& operator<<(ostream&, const Circle&);
public:
	Circle(double n = 0.0, int a = 0,int b = 0):Point(a,b)
	{
		radius = (n >= 0 ? n:0);
	}
protected:
	double radius;
};

ostream& operator<<(ostream& os,const Circle& c)
{
	os << "The center of the circle is at " << (Point)c;
	os << "The radius is " <<setprecision(2)<<fixed<<showpoint << c.radius;
	os << endl;
	return os;
}

int main()
{
	Point a, b(5, 5);
	cout << a << b<<endl;
	Circle c,d(4.5,1,2);
	cout << c << d;
	return 0;
}

#define _crt_secure_no_warnings
#include<iostream>
using namespace std;

class Prop {
public:
	int num;
	int yes;
	int no;
	int total;
	float peryes;
	Prop(int, int, int, int, float);
	Prop(int, int, int);
	bool operator<=(const Prop& prop) const
	{
		return peryes <= prop.peryes;
	}
	Prop operator+(const Prop&) const;
	Prop& operator++();
	Prop operator++(int);
	friend ostream& operator<<(ostream& os, const Prop& prop);
	friend istream& operator>>(istream& is, Prop& prop);
};

Prop::Prop(int num, int y, int no, int t, float pery)
{
	this->num = num;
	this->yes = y;
	this->no = no;
	this->total = t;
	this->peryes = pery;
}

Prop::Prop(int number, int y, int n)
{
	num = number;
	yes = y;
	no = n;
	total = yes + no;
	peryes = yes / (float)total * 100;
}

Prop& Prop::operator++()
{
	yes++;
	total++;
	peryes = yes / (float)total * 100;
	return *this;
}

Prop Prop::operator++(int)
{
	Prop temp = *this;
	yes++;
	total++;
	peryes = yes / (float)total * 100;
	return temp;
}

Prop Prop::operator+(const Prop& prop) const
{
	return Prop(num, yes + prop.yes, no + prop.no, total + prop.total, (yes + prop.yes) / (float)(total + prop.total) * 100);
	return Prop(num, yes + prop.yes, no + prop.no);
}

ostream& operator<<(ostream& os, const Prop& prop)
{
	os << "Proposition numer : " << prop.num << endl;
	os << "Yes vote : " << prop.yes << endl;
	os << "No vote : " << prop.no << endl;
	os << "Total vote : " << prop.total << endl;
	os << "Percentage of yes vote : " << prop.peryes << endl;
	return os;
}

istream& operator>>(istream& is, Prop& prop)
{
	is >> prop.num >> prop.yes >> prop.no;
	prop.total = prop.yes + prop.no;
	prop.peryes = prop.yes / (float)prop.total;
	return is;
}

int main()
{
	Prop prop111(111, 111, 5), PROP111(111,6,10);
	cout << prop111<<PROP111;
	cout << prop111 + PROP111;
	cout << prop111++;
	cout << prop111;
	cout << ++prop111;
	if (prop111 <= PROP111)
	{
		printf("PROP 111 per yes is <= prop 111\n");
	}
	else
	{
		printf("PROP 111 per yes is not <= prop 111\n");
	}
	Prop p(1,2,3);
	cin >> p;
	cout << p;
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Student
{
public:
	Student(int = 0, int = 0, int = 0);
	friend std::ostream& operator<<(std::ostream&, const Student&);
	friend std::istream& operator>>(std::istream&, Student&);
	Student& operator+=(int);
	Student& operator++();
	Student operator++(int);
private:
	int test1, test2, test3;
	float avg;
};

Student::Student(int t1, int t2, int t3)
{
	test1 = t1;
	test2 = t2;
	test3 = t3;
	avg = (t1 + t2 + t3) / (float)3;
}

std::ostream& operator<<(std::ostream& os, const Student& pupil)
{
	os << "test 1: " << pupil.test1 << std::endl;
	os << "test 2: " << pupil.test2 << std::endl;
	os << "test 3: " << pupil.test3 << std::endl;
	os << "avg: " << pupil.avg << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Student& pupil)
{
	is >> pupil.test1 >> pupil.test2 >> pupil.test3;
	pupil.avg = (pupil.test1 + pupil.test2 + pupil.test3) / (float)3;
	return is;
}

Student& Student::operator+=(int num)
{
	test1 += num;
	test2 += num;
	test3 += num;
	avg = (test1 + test2 + test3) / (float)3;

	return *this;
}

Student& Student::operator++()
{
	test1++;
	test2++;
	test3++;
	avg = (test1 + test2 + test3) / (float)3;
	return *this;
}

Student Student::operator++(int)
{
	Student temp = *this;
	++(*this);
	return temp;
}

int main()
{

	Student one, two(10,20,30), three(1,2,3);
	std::cout << "Student one: \n" << one << std::endl;
	one += 5;
	std::cout << "Student one += 5\n" << one<<std::endl;
	std::cout << "Student two: \n" << two << std::endl;
	std::cout << "Student two preincrement: \n" << ++two << std::endl;
	std::cout << "Student three: \n" << three << std::endl;
	std::cout << "Student three postincrement: \n" << three++ << std::endl;
	std::cout << "Student three after post increment: \n" << three << std::endl;

	return 0;
}


#define _crt_secure_no_warnings
#include<iostream>

class Student
{
public:
	friend class Person;
	Student()
	{
		test1 = test2 = test3 = big = small = 0;
	}
private:
	int test1, test2, test3, big, small;
	int biggest(int t1, int t2, int t3)
	{
		int largest = t1;
		if (largest < t2)
			largest = t2;
		if (largest < t3)
			largest = t3;
		return largest;
	}
	int smallest(int t1, int t2, int t3)
	{
		int smallest = t1;
		if (smallest > t2)
			smallest = t2;
		if (smallest > t3)
			smallest = t3;
		return smallest;
	}
};

class Person 
{
public:
	Student s;
	int stock1, stock2, stock3, big, small;
	void getinfo();
	Person()
	{
		getinfo();
	}
};

void Person::getinfo()
{
	std::cout << "enter three stock values.:\n";
	std::cin >> stock1 >> stock2 >> stock3;
	std::cout << "The three stock values are: " << stock1 << " " << stock2 << " " << stock3 << std::endl;
	big = s.biggest(stock1, stock2, stock3);
	small = s.smallest(stock1, stock2, stock3);
	std::cout << "the biggest stock value is " << big << "\nthe smallest stock value is " << small << std::endl;
}

int main()
{
	Person p;
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main()
{
	int n = 0;
	std::cout << "Enter a number: ";
	std::cin >> n;
	int factorial = 1;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
		sum += factorial;
	}

	std::cout <<n<<"'s factorial is "<< factorial << std::endl;
	std::cout << n << "'s sum of the factorial is " << sum << std::endl;

	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>

// demonstration of the this pointer to cascade member function calls
class Student 
{
public:
	Student(int = 0, int = 0, int = 0);
	~Student();
	Student& getData(int, int, int);
	Student& setTest1(int);
	Student& setTest2(int);
	Student& setTest3(int);
	int getTest1() const;
	int getTest2() const;
	int getTest3() const;
	void printData() const;
private:
	int test1;
	int test2;
	int test3;

};

Student::Student(int t1, int t2, int t3)
{
	getData(t1, t2, t3);

}

Student::~Student()
{
	std::cout << "Test1: " << test1 << " Test2: " << test2 << " Test3: " << test3 << " destroyed.\n\n";
}

Student& Student::getData(int t1, int t2, int t3)
{
	setTest1(t1);
	setTest2(t2);
	setTest3(t3);
	return *this;
}

Student& Student::setTest1(int t1)
{
	test1 = t1;
	return *this;
}

Student& Student::setTest2(int t2)
{
	test2 = t2;
	return *this;
}

Student& Student::setTest3(int t3)
{
	test3 = t3;
	return *this;
}

int Student::getTest1() const
{
	return test1;
}

int Student::getTest2() const
{
	return test2;
}

int Student::getTest3() const
{
	return test3;
}

void Student::printData() const
{
	std::cout << "Test1: " <<std::setw(6)<< test1<<std::endl;
	std::cout << "Test2: " << std::setw(6) << test2<< std::endl;
	std::cout << "Test3: " << std::setw(6) << test3<< std::endl;
	std::cout<< std::endl;
}

int main()
{
	Student one, two;
	one.setTest1(10).setTest2(20).setTest3(30);
	// cascade member function calls
	std::cout << "student one data is" << std::endl;
	one.printData();
	std::cout << std::endl << "student two data is" << std::endl;
	two.getData(50, 60, 70).printData();
	std::cout << std::endl;

	int test1 = two.getTest1();
	std::cout << "student two first test score is " << test1<< std::endl;

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

//multiple inheritage

class Person 
{
public:
	Person(std::string name, int age);
	virtual void introduce();
protected:
	std::string name;
	int age;
};

Person::Person(std::string theName, int theAge)
{
	name = theName;
	age = theAge;
}

void Person::introduce()
{
	std::cout << "My name is " << name << " and I am " << age << " years old." << std::endl;
}
class Student:public Person
{
public:
	Student(std::string, int,std::string);
	void study();
	void introduce();
protected:
	std::string major;
};

Student::Student(std::string theName, int theAge, std::string major) :Person(theName, theAge)
{
	this->major = major;
}

void Student::introduce()
{
	std::cout <<"My name is " << name << " and I am a student major in "<<major<<". " << std::endl;
}

void Student::study()
{
	std::cout << "student styding.\n";
}

class Teacher:public Person
{
public:
	Teacher(std::string, int, std::string);
	void teach();
protected:
	std::string classTeaching;
};

Teacher::Teacher(std::string theName, int theAge, std::string classTeach) :Person(theName, theAge)
{
	classTeaching = classTeach;
}

void Teacher::teach()
{
	std::cout << "my name is " << name << " and  I am teaching " << classTeaching << ". "<< std::endl;
}

class TA:public Teacher,public Student
{
public:
	TA(std::string, int, std::string, std::string);
	void introduce();
};

TA::TA(std::string theName, int theAge, std::string classTeaching, std::string classAttending)
	:Teacher(theName,theAge,classTeaching),
	Student(theName, theAge,classAttending)
{
	
}

void TA :: introduce()
{
	std::cout << "my name is " << Student::name << " and I am a TA.\n";
	std::cout << "I am teaching " << Teacher::classTeaching << ".\n";
	std::cout << "And also I am studying " << Student::major << std::endl;
}

int main()
{
	Student andrew("andrew", 25, "statistic");
	Teacher janna("janna", 40, "calculus");
	TA cola("cola", 23, "trigonometry", "calculus");
	andrew.introduce();
	andrew.study();
	std::cout << std::endl;
	janna.introduce();
	janna.teach();
	cola.introduce();
	cola.study();
	cola.teach();

	return 0;
}

#include<iostream>

class SeqList 
{
public:
	SeqList();
	~SeqList();
	void InitList();
	void listPushback();
	void listPopback();
	void listPushfront();
	void listPopfront();
	void listInsert();
	void listErase();
	void listFind();
	void listReverse();
	void listSort();
	
private:
	int *m_pData;
	int m_iLength;
	int m_iCapacity;
};

int main()
{
	//this program will create a sequence list
	//and then print the list
	//and then delete the list
		
	return 0;
}

#include<iostream>

//this function returns an array of fibonacci sequence
long long* Fib(int n)
{
	if (n == 0)
	{
		return NULL;
	}
	long long* fib = new long long[n+1];
	fib[0] = 0;
	fib[1] = 1;
	if(n>=3)
	for (int i = 2; i < n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	return fib;
}


int main()
{
	const int n = 8;
	long long* Fibb = Fib(n);
	for (int i = 0; i < n; i++)
	{
		std::cout << Fibb[i] << std::endl;
	}
	delete Fibb;
	return 0;
}


#include<iostream>
using namespace std;
int main()
{
	char arr[10] = { 0 };
	cin.getline(arr, 10);
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		//ASCII 
		if ((arr[i]>=65&&arr[i]<=90)||(arr[i]>=97&&arr[i]<=122))
		{
			count++;
		}
	}
	if (count)
		cout << "valid.\n";
	else
		cout << "invalid.\n";

	return 0;
}

#include<iostream>

int timeComplexity(int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count++;
	}
	for (int t = 0; t < 2*n; t++)
	{
		count++;
	}

	int M = 10;
	while (M--)
	{
		count++;
	}
	return count;
}

int main()
{
	std::cout << "enter a number:>";
	int x;
	std::cin >> x;
	int y = timeComplexity(x);
	std::cout << "time complexity is :"<< y;
	//时间复杂度就是这个程序跑了多少次
	//因为每个机器的用时都不一样，好机器跑得快，差机器跑的慢。
	//算不出具体时间
	//就算跑了多少次就是时间复杂度
}

#include<iostream>

class Test {
public:
	Test(int = 0, int = 0);
	~Test();
	friend std::ostream& operator<<(std::ostream&, Test);
private:
	int x;
	int y;
};

Test::Test(int x, int y)
{
	this->x = x;
	this->y = y;
}

Test::~Test()
{
	std::cout << "(" << x << "," << y << ")" << " destroyed.\n";
}

std::ostream& operator<<(std::ostream&, Test x);

int main()
{
	Test t1, t2(1,2),t3(3,4);
	std::cout<<t1<<t2<<t3;//cout调用重载<<函数复制了一个进去
	//所以析构器被执行了
	//然后出了作用域自动分解
	return 0;
}

std::ostream& operator<<(std::ostream& os, Test x)
{
	std::cout << "x = " << x.x << ", y = " << x.y << std::endl;
	return os;
}


#include<iostream>

class Student {
public:
	Student();
	~Student();
	void setData(int a);
	void addData(Student&, Student&);
	void printData();
private:
	int test;
};

Student::Student()
{
	test = 1;
}

Student::~Student()
{
	std::cout << "destructed.\n";
}

void Student::addData(Student& a, Student& b)
{
	test = a.test + b.test;
}

void Student::setData(int a)
{
	test = a;
}

void Student::printData()
{
	std::cout << "test: " << test << std::endl;
}
int main()
{
	Student one, two, three;
	one.printData();
	two.setData(59);
	two.printData();
	three.addData(one, two);
	three.printData();
	return 0;
}


#include<iostream>

class Student
{
public:
	Student(int=0, int = 0, int = 0);
	~Student();
	void setData(int a,int b,int c);
	int getTest1();
	int getTest2();
	int getTest3();
	void printData();
private:
	int test1, test2, test3;
	int* test = new int;
};

Student::Student(int a, int b, int c)
{
	setData(a,b,c);
}

Student::~Student()
{
	std::cout << "deleted." << std::endl;
	delete test;
}

void Student::setData(int a, int b, int c)
{
	test1 = a;
	test2 = b;
	test3 = c;
	*test = a;
}

int Student::getTest1()
{
	return test1;
}

int Student::getTest2()
{
	return test2;
}

int Student::getTest3()
{
	return test3;
}

void Student::printData()
{
	std::cout << "Test1: " << test1 << " Test2: " << test2 << " Test3: " << test3 << std::endl << std::endl;
	std::cout << "Test* " << *test << std::endl;
}

void addPoint(Student& input);

int main()
{
	Student* s1 = new Student(30,50,80);
	s1->printData();
	addPoint(*s1);
	s1->printData();
	delete s1;

	return 0;
}

void addPoint(Student& input)
{
	input.setData(input.getTest1(),input.getTest2()+20, input.getTest3()+30);
}

#include<iostream>
#include<iomanip>
using namespace std;

class Student {
public:
	Student(string input, int = 0, int = 0, int = 0);
	~Student();
	void setData(string, int, int, int);
	void setTest1(int);
	void setTest2(int);
	void setTest3(int);
	int getTest1();
	int getTest2();
	int getTest3();
	void printData();
private:
	int test1, test2, test3;
	string name;
};

Student::Student(string input, int a, int b, int c)
{
	setData(input, a, b, c);
}

Student::~Student()
{
	std::cout <<name<< " destroyed.\n";
}

void Student::setData(string input, int a, int b, int c)
{
	name = input;
	test1 = a;
	test2 = b;
	test3 = c;
}

void Student::setTest1(int a)
{
	test1 = a;
}
void Student::setTest2(int a)
{
	test2 = a;
}
void Student::setTest3(int a)
{
	test3 = a;
}

int Student::getTest1()
{
	return test1;
}
int Student::getTest2()
{
	return test2;
}
int Student::getTest3()
{
	return test3;
}

void Student::printData()
{
	cout << "|" << setw(15) << "NAME" << "|"
		<<setw(8)<<"TEST 1"<< "|"
		<< setw(8) << "TEST 2" << "|"
		<< setw(8) << "TEST 3" << "|"<<endl;
	cout<<"|"<<setw(15)<<name<<"|"
		<<setw(8)<<test1<<"|"
		<<setw(8)<<test2<<"|"
		<< setw(8) << test3 << "|" << endl;
}
int main()
{
	Student s1("andrew"), s2("vika"), s3("jing"), s4("dee");
	cout << "default argument is\n\n";
	s1.printData();
	cout << "Data set 1:\n\n";
	s2.setTest1(20);
	s2.printData();
	cout << "Data set 2:\n\n";
	s3.setTest2(50);
	s3.printData();
	s4.setTest3(80);
	s4.printData();
	int test3 = s4.getTest3();
	cout << "Data get" << test3 << endl;
	return 0;
}


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

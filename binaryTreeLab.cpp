#define CRT_SECURE_NO_WARNINGS
#include<iostream>

template<class T>
class BinaryTree {
public:
	BinaryTree(const int& size = 16):_count(0)
	{
		_data = new int[size];
		_capacity = size;
	}
	void Add(const T& data)
	{
		if (_count == _capacity)
		{
			T* tmp = new T[_capacity * 2];
			_capacity *= 2;
			for (int i = 0; i < _count; i++)
			{
				tmp[i] = _data[i];
			}
			delete[] _data;
			_data = tmp;
		}
		_data[_count] = data;
		_count++;
	}

	void PrevOrder()
	{
		_PrevOrder(0);
	}

	~BinaryTree() 
	{
		delete[] _data;
	}

private:
	T* _data;
	int _count;
	int _capacity;

	void _PrevOrder(int root)
	{
		if (root >= _count)
			return;
		std::cout << _data[root] << " ";
		_PrevOrder(root * 2 + 1);
		_PrevOrder(root * 2 + 2);
	}
};


int main()
{
	BinaryTree<int> bt;
	bt.Add(1);
	std::cout << "adding 1, preorder print:";
	bt.PrevOrder();
	std::cout << std::endl;
	bt.Add(2);
	std::cout << "adding 2, preorder print:";
	bt.PrevOrder();
	std::cout << std::endl;
	bt.Add(3);
	std::cout << "adding 3, preorder print:";
	bt.PrevOrder();
	std::cout << std::endl;
	bt.Add(4);
	std::cout << "adding 4, preorder print:";
	bt.PrevOrder();
	std::cout << std::endl;
	bt.Add(5);
	std::cout << "adding 5, preorder print:";
	bt.PrevOrder();
	std::cout << std::endl;
	bt.Add(6);
	std::cout << "adding 6, preorder print:";
	bt.PrevOrder();
	std::cout << std::endl;
	bt.Add(7);
	std::cout << "adding 7, preorder print:";
	bt.PrevOrder();
	std::cout << std::endl;

	return 0;
}

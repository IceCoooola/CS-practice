#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
/*
1. Read data for names and weights for 15 people from the console 
where there is a name on a line followed by a weight on the next line, like in names.txt.

2. Your program will build a list for the data maintained in ascending order based on both name and weight via a doubly linked list.

3. This dll will use one pointer to keep weights in sorted order, and use the other link to keep names on sorted order.

4. You need to build the list as you go maintaining this ordering, 
so at any time a print method was called it would print the related field in order. 

(This means nodes are added to the list in sorted order, elements are not added to the list followed by a sort called on the list.)

For example after 3 elements are added for (Name – Weight):
Michael – 275, Tom – 150, Abe – 200.

Output:
Names & weights sorted(ascending) by name. : Abe – 200, Michael – 275, Tom - 150
Names & weights sorted(ascending) by weight. : Tom – 150, Abe – 200, Michael - 275
*/

struct memberInfo
{
	memberInfo(const string& name, const int weight):_name(name), _weight(weight) {}
	int _weight;
	string _name;
};

struct ListNode
{
	ListNode(const string& name, const int weight) :_data(name, weight),_prev(nullptr),_next(nullptr){}
	memberInfo _data;
	ListNode* _prev;
	ListNode* _next;
};

class Member 
{
public:
	Member(){
		_linkBaseOnName = new ListNode("headptr", 0);
		_linkBaseOnName->_next = _linkBaseOnName;
		_linkBaseOnName->_prev = _linkBaseOnName;
		_linkBaseOnWeight = new ListNode("headptr", 0);
		_linkBaseOnWeight->_next = _linkBaseOnWeight;
		_linkBaseOnWeight->_prev = _linkBaseOnWeight;
	}

	void AddMember(const string& name, const int weight)
	{
		//add new node to name based sorted linked list
		ListNode* newNode = new ListNode(name, weight);
		ListNode* cur = _linkBaseOnName->_next;
		while (cur != _linkBaseOnName)
		{
			if (cur->_data._name.compare(name) < 0)
			{
				cur = cur->_next;
			}
			else
			{
				break;
			}
		}
		cur->_prev->_next = newNode;
		newNode->_next = cur;
		newNode->_prev = cur->_prev;
		cur->_prev = newNode;

		//add new node to weight based sorted linked list
		ListNode* newNode2 = new ListNode(name, weight);
		cur = _linkBaseOnWeight->_next;
		while (cur != _linkBaseOnWeight)
		{
			if (cur->_data._weight < weight)
			{
				cur = cur->_next;
			}
			else
			{
				break;
			}
		}
		cur->_prev->_next = newNode2;
		newNode2->_next = cur;
		newNode2->_prev = cur->_prev;
		cur->_prev = newNode2;
	}

	void printByName()
	{
		ListNode* cur = _linkBaseOnName->_next;
		while (cur != _linkBaseOnName)
		{
			std::cout << cur->_data._name << " -- " << cur->_data._weight << endl;
			cur = cur->_next;
		}
	}

	void printByWeight()
	{
		ListNode* cur = _linkBaseOnWeight->_next;
		while (cur != _linkBaseOnWeight)
		{
			std::cout << cur->_data._name << " -- " << cur->_data._weight << endl;
			cur = cur->_next;
		}
	}

	~Member()
	{
		ListNode* curName = _linkBaseOnName->_next;
		ListNode* curWeight = _linkBaseOnWeight->_next;
		while (curWeight != _linkBaseOnWeight && curName != _linkBaseOnName)
		{
			ListNode* nextWeight = curWeight->_next;
			ListNode* nextName = curName->_next;
			delete curWeight;
			delete curName;
			curName = nextName;
			curWeight = nextWeight;
		}
		delete _linkBaseOnName;
		_linkBaseOnName = nullptr;
		delete _linkBaseOnWeight;
		_linkBaseOnWeight = nullptr;
	}
private:
	ListNode* _linkBaseOnWeight;
	ListNode* _linkBaseOnName;
};

int main()
{
	string name;
	int weight;
	Member m;
	for (int i = 0; i < 6; i++)
	{
		cout << "enter a member name:\n";
		cin >> name;
		cout << "enter the member's weight:\n";
		cin >> weight;
		m.AddMember(name, weight);
	}
	m.printByName();
	m.printByWeight();
	return 0;
}

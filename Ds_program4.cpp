//  main.cpp
//  program 4
//
//  Created by Di Bao on 11/15/22.
//
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include <queue>
using namespace std;

template<class K, class V>
struct Node
{
    K _key;
    V _value;
    Node* _next;
    Node(const pair<K, V>& data) :_key(data.first), _value(data.second), _next(nullptr) {}
};

template<class T>
struct Hash
{
    size_t operator()(const T& input)
    {
        return input;
    }
};

template<>
struct Hash<string>
{
    size_t operator()(const string& key)
    {
        int ret = 0;
        int i = 1;
        for (auto ch : key)
        {
            ret += ch * i;
            i++;
        }
        return ret;
    }
};

enum COMMAND
{
    START = 1,
    FINISH,
    COM,
    NEWVAR,
    VAR,
    PRINT
};

COMMAND BORGCommand(const string& str)
{
    if (str == "START")
        return START;
    else if (str == "FINISH")
        return FINISH;
    else if (str == "COM")
        return COM;
    else if (str == "VAR")
        return NEWVAR;
    else if (str == "PRINT")
        return PRINT;
    else
        return VAR;
}

template<class K, class V>
class HashTable
{
    typedef Node<K, V> HashNode;
public:
    HashTable(const int& size)
    {
        _hashTable.resize(size, nullptr);
    }

    bool insert(const pair<K, V>& data)
    {
        HashNode* ret = find(data.first);
        //check if data already exist
        if (ret)
            return false;
        ++_n;
        if (_n == _hashTable.size())
        {
            vector<HashNode*> newTable;
            int size = _n * 2;
            newTable.resize(size, nullptr);
            for (int i = 0; i < _hashTable.size(); i++)
            {
                HashNode* cur = _hashTable[i];
                while (cur)
                {
                    HashNode* next = cur->_next;
                    Hash<K> hf;
                    size_t index = hf(cur->_key) % newTable.size();
                    cur->_next = newTable[index];
                    newTable[index] = cur;
                    cur = next;
                }
                _hashTable[i] = nullptr;
            }
            _hashTable.swap(newTable);
        }
        Hash<K> hf;
        int i = hf(data.first) % _hashTable.size();
        HashNode* cur = _hashTable[i];
        if (!cur)
        {
            _hashTable[i] = new HashNode(data);
        }
        else
        {
            HashNode* newNode = new HashNode(data);
            HashNode* prev = _hashTable[i];
            newNode->_next = prev;
            _hashTable[i] = newNode;
        }
        return true;

    }

    HashNode* find(const K& key)
    {
        Hash<K> hf;
        int i = hf(key) % _hashTable.size();
        HashNode* cur = _hashTable[i];
        while (cur)
        {
            if (cur->_key == key)
                return cur;
            else
                cur = cur->_next;
        }
        return nullptr;
    }

    V& operator[](const K& key)
    {
        HashNode* ret = find(key);
        if (!ret)
        {
            cout << "data does not exists.\n";
            throw;
        }
        return ret->_value;
    }

    void printTable()
    {
        for (int i = 0; i < _hashTable.size(); i++)
        {
            HashNode* j = _hashTable[i];
            while (j)
            {
                cout << j->_key << " is " << j->_value << endl;
                j = j->_next;
            }
        }
    }

    bool printOneKV(const K& key)
    {
        HashNode* ret = find(key);
        if (!ret)
            return false;
        else
            cout << ret->_key << " is " << ret->_value << endl;
        return true;
    }

    void printWithOperator(const char& operation, const string& key, const string& value)
    {
        V val = find(key)->_value;
        V tmp = stof(value);
        switch (operation)
        {
        case '+':
            cout << key << " " << operation << " " << value <<" is "<< val + tmp;
            break;
        case '-':
            cout << key << " " << operation << " " << value <<" is "<< val - tmp;
            break;
        case '*':
            cout << key << " " << operation << " " << value <<" is "<< val * tmp;
            break;
        case '/':
            cout << key << " " << operation << " " << value <<" is "<< val / tmp;
            break;
        case '%':
            while(val >= 0)
            {
                val -= tmp;
            }
            val += tmp;
            cout << key << " " << operation << " " << value <<" is "<< val;
            break;
        default:
            cout << "error printing operator. \n";
        }

    }
private:
    vector<HashNode*> _hashTable;
    size_t _n;
};

template<class K, class V>
bool createNewVar(queue<K>& q, HashTable<K, V>& hsTable)
{
    if (q.empty())
        return false;
    q.pop();
    K key = q.front();
    q.pop();
    if (q.empty())
        return false;
    if (q.front() != "=")
        return false;
    q.pop();
    if (q.empty())
        return false;
    V value = stof(q.front());
    hsTable.insert(make_pair(key, value));
    while (!q.empty())
    {
        q.pop();
    }
    return true;
}

template<class K, class V>
void reviseVar(queue<K>& q, HashTable<K, V>& var)
{
    Node<K, V>* ret = var.find(q.front());
    q.pop();
    if (q.front() == "++")
    {
        ret->_value++;
        q.pop();
    }
    else if (q.front() == "--")
    {
        ret->_value--;
        q.pop();
    }
    else if (q.front() == "=")
    {
        q.pop();
        ret->_value = stof(q.front());
        q.pop();
    }
    else
    {
        char sign = q.front()[0];
        q.pop();
        V value = stof(q.front());
        q.pop();
        switch (sign) {
        case '+':
            ret->_value += value;
            break;
        case '-':
            ret->_value -= value;
            break;
        case '*':
            ret->_value *= value;
            break;
        case '/':
            ret->_value /= value;
            break;
        case '%':
            while(ret->_value >= 0)
            {
                ret->_value -= value;
            }
            ret->_value += value;
            break;
        case '^':
            while (--value)
            {
                V tmp = ret->_value;
                ret->_value *= tmp;
            }
            break;
        default:
            break;
        }
    }
}

int main()
{
    HashTable<string, float> GlobalVar(25);
    ifstream ifs("test.txt");
    string str;
    string name;
    while (getline(ifs, str))
    {
        stringstream stringstr(str);
        queue<string> q;
        stringstr >> str;

        if (BORGCommand(str) == COM)
        {
            continue;
        }

        if (BORGCommand(str) == START)
        {
            HashTable<string, int> LocalVar(25);
            while (getline(ifs, str))
            {
                stringstream stringstr2(str);
                stringstr2 >> str;
                if (BORGCommand(str) == COM)
                    continue;
                if (BORGCommand(str) == FINISH)
                    break;
                q.push(str);
                while (stringstr2 >> str)
                {
                    q.push(str);
                }
                switch (BORGCommand(q.front())) {
                case NEWVAR:
                    if (!createNewVar(q, LocalVar))
                        cout << "create variable false. Please check expression.\n";
                    break;
                case VAR:
                    //find local var first and find global var
                    if (!LocalVar.find(q.front()))
                    {
                        if (!GlobalVar.find(q.front()))
                        {
                            cout << q.front() << " does not exists.\n";
                        }
                        else
                        {
                            //check expression next ++ -- in global variable
                            reviseVar(q, GlobalVar);
                        }
                    }
                    else
                    {
                        //check expression next ++ -- in local variable
                        reviseVar(q, LocalVar);
                    }
                    break;
                case PRINT:
                    q.pop();
                    //if printing variable only
                    if (q.size() == 1)
                    {
                        //find local var && find global var
                        if (!LocalVar.printOneKV(q.front()))
                        {
                            if (!GlobalVar.printOneKV(q.front()))
                            {
                                cout << q.front() << " does not exists.\n";
                            }
                        }
                    }
                    else
                    {
                        if (!LocalVar.find(q.front()))
                        {
                            if (!GlobalVar.find(q.front()))
                            {
                                cout << q.front() << " does not exists.\n";
                            }
                            else
                            {
                                string tmp = q.front();
                                q.pop();
                                char operation = q.front()[0];
                                q.pop();
                                GlobalVar.printWithOperator(operation, tmp, q.front());
                            }
                        }
                        else
                        {
                            string tmp = q.front();
                            q.pop();
                            char operation = q.front()[0];
                            q.pop();
                            LocalVar.printWithOperator(operation, tmp, q.front());
                        }
                    }
                    while (!q.empty())
                    {
                        q.pop();
                    }
                    break;
                default:
                    cout << "switch case error.\n";
                    throw;
                    break;
                }
            }
        }
        if (BORGCommand(str) == FINISH)
        {
            continue;
        }
        q.push(str);
        while (stringstr >> str)
        {
            q.push(str);
        }
        switch (BORGCommand(q.front())) {
        case NEWVAR:
            if (!createNewVar(q, GlobalVar))
                cout << "create variable false. Please check expression.\n";
            break;
        case VAR:
            //find local var first and find global var
            if (!GlobalVar.find(q.front()))
            {
                cout <<q.front() << " does not exists.\n";
            }
            else
            {
                //check expression next ++ -- in local variable
                reviseVar(q, GlobalVar);
            }
            break;
        case PRINT:
            q.pop();
            if (!GlobalVar.find(q.front()))
            {
                cout << q.front() << " does not exists.\n";
                break;
            }
            if (q.size() == 1)
            {
                //find local var && find global var
                if (!GlobalVar.printOneKV(q.front()))
                {
                    cout << q.front() << " does not exists.\n";
                }
            }
            else
            {
                string tmp = q.front();
                q.pop();
                char operation = q.front()[0];
                q.pop();
                GlobalVar.printWithOperator(operation, tmp, q.front());
            }
            while (!q.empty())
            {
                q.pop();
            }
            break;
        default:
            cout << "switch case error.\n";
            throw;
            break;
        }
    }

    return 0;
}

//  main.cpp
//  program 4
//
//  Created by Di Bao on 11/15/22.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <sstream>
using namespace std;

struct Node
{
    string _key;
    int _value;
    Node* _next;
    Node(const pair<string, int>& data):_key(data.first),_value(data.second),_next(nullptr){}
};

struct Hash
{
    size_t operator()(const string& key)
    {
        int ret = 0;
        int i = 1;
        for(auto ch : key)
        {
            ret += ch * i;
            i++;
        }
        return ret;
    }
};

class HashTable
{
    typedef Node HashNode;
public:
    HashTable(const int& size)
    {
        _hashTable.resize(size, nullptr);
    }
    
    bool insert(const pair<string, int>& data)
    {
        HashNode* ret = find(data.first);
        //check if data already exist
        if(ret)
            return false;
        ++_n;
        if(_n == _hashTable.size())
        {
            vector<HashNode*> newTable;
            int size = _n * 2;
            newTable.resize(size, nullptr);
            for(int i = 0; i < _hashTable.size();i++)
            {
                HashNode* cur = _hashTable[i];
                while(cur)
                {
                    HashNode* next = cur->_next;
                    Hash hf;
                    int hashVal = hf(cur->_key);
                    size_t index = hashVal % newTable.size();
                    cur->_next = newTable[index];
                    newTable[index] = cur;
                    cur = next;
                }
                _hashTable[i] = nullptr;
            }
            _hashTable.swap(newTable);
        }
        Hash hf;
        int i = hf(data.first) % _hashTable.size();
        HashNode* cur = _hashTable[i];
        if(!cur)
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
    
    HashNode* find(const string& key)
    {
            Hash hf;
            int i = hf(key) % _hashTable.size();
            HashNode* cur = _hashTable[i];
            while(cur)
            {
                if(cur->_key == key)
                    return cur;
                else
                    cur = cur->_next;
            }
        return nullptr;
    }
    
    int& operator[](const string& key)
    {
        HashNode* ret = find(key);
        if(!ret)
        {
            throw;
        }
        return ret->_value;
    }
    
    void printTable()
    {
        for(int i = 0; i< _hashTable.size(); i++)
        {
            HashNode* j = _hashTable[i];
            while(j)
            {
                cout<< j->_key<<" is "<<j->_value << endl;
                j = j->_next;
            }
        }
    }
    
private:
    vector<HashNode*> _hashTable;
    size_t _n;
};

int main() {
    HashTable ht(25);
    ht.insert(make_pair("test1", 1));
    ht.insert(make_pair("test", 2));
    ht.insert(make_pair("test3", 3));
    ht.insert(make_pair("test22", 22));
    ht.insert(make_pair("test222", 2222));
    ht.printTable();
    ifstream ifs("text.txt");
    string str;
    while(getline(ifs, str))
    {
        stringstream stringstr(str);
        vector<string> vct;

    }

    return 0;
}

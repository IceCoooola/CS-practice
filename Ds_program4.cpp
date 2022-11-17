//  main.cpp
//  program 5
//
//  Created by Di Bao on 11/15/22.
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template<class Key, class Value>
struct Node
{
    Key _key;
    Value _value;
    Node* _next;
};

template<class K>
struct Hash{
    size_t operator()(const K& key)
    {
        return key;
    }
};

template<>
struct Hash<string>
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

template<class Key, class Value>
class HashTable
{
    typedef Node<Key, Value> HashNode;
public:
    HashTable(const int& size)
    {
        _hashTable.resize(size, nullptr);
    }
    Value& operator[](const Key& key)
    {
        Value& ret = find(key);
    }
    Value& find(const Key& key)
    {
        
    }
private:
    vector<HashNode*> _hashTable;
};

int main() {
    return 0;
}

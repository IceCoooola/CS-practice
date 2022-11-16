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
        for(auto ch : key)
        {
            ret += ch;
            ret *= 131;
        }
        return ret;
    }
};

template<class Key, class Value>
class HashTable
{
    typedef Node<Key, Value> HashNode;
public:
    Value& operator[](const Key& key)
    {
        
    }
private:
    vector<HashNode*> _hashTable;
};

int main() {
    return 0;
}

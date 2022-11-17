//  main.cpp
//  program 5
//
//  Created by Di Bao on 11/15/22.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

template<class Key, class Value>
struct Node
{
    Key _key;
    Value _value;
    Node* _next;
    Node(const pair<Key, Value>& data):_key(data.first),_value(data.second),_next(nullptr){}
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
    
    bool insert(const pair<Key, Value>& data)
    {
        HashNode* ret = find(data.first);
        //check if data already exist
        if(ret)
            return false;
        int i = hash<Key>(data.first);
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
    
    HashNode* find(const Key& key)
    {
        
            int i = hash<Key>(key);
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
    
private:
    vector<HashNode*> _hashTable;
};

int main() {
    return 0;
}

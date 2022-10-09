//
//  main.cpp
//  program3
//
//  Created by Di Bao on 10/8/22.
//

#include <iostream>
#include <vector>
#include<utility>
using namespace std;

template<class K, class V>
struct BSTreeNode
{
    BSTreeNode* _left;
    BSTreeNode* _right;
    K _key;
    V _value;
    BSTreeNode(K key, V value):_left(nullptr), _right(nullptr), _key(key),_value(value){}
};

template<class K, class V>
class BinarySearchTree
{
    typedef BSTreeNode<K, V> Node;
public:
    BinarySearchTree():_root(nullptr){}
    //functionality1: build the tree from the unique set of names and their associated weights
    BinarySearchTree(const vector<pair<K, V>>& data)
    {
        for(int i = 0; i < data.size();i++)
        {
            Add(data[i].first, data[i].second);
        }
    }
    
    bool Add(const K& key, const V& value)
    {
        if(!_root)
        {
            _root = new Node(key, value);
            return true;
        }
        
        Node* cur = _root;
        Node* parent = nullptr;
        while(cur)
        {
            if(cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else if(cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else
            {
                cout<<"data exist, "<<key <<" failed to add.\n";
                return false;
            }
        }
        Node* newNode = new Node(key, value);
        if(key > parent->_key)
        {
            parent->_right = newNode;
        }
        else
        {
            parent->_left = newNode;
        }
        return true;
    }
    //functionality 2: execute a preorder traversal
    void preOrder()
    {
        _preOrder(_root);
        cout<<endl;
    }
    //functionality 3: execute a inorder traversal
    void inOrder()
    {
        _inOrder(_root);
        cout<<endl;
    }
    //functionality 4: execute a postorder traversal
    void postOrder()
    {
        _postOrder(_root);
        cout<<endl;
    }
    //functionality 5: find and print the height of the tree using recursion
    void findHeight()
    {
        cout<<"the height of the tree is : "<< _findHeight(_root)<<endl;
    }
    //functionality 6: determine the number of leaves
    void findLeave()
    {
        cout<<"the tree have "<< _findLeave(_root)<<" leaves\n";
    }
    //functionality 7: implement search that will search for a name and indicate the weight for that individual if they exist in the structure
    void find(const K& key)
    {
        Node* ret = _find(key, _root);
        if(ret)
            cout<<"the corresponding value is :" << ret->_value << endl;
        else
            cout<<"no match exists\n";
    }
    //functionality 8:determine the lowest weight contained in the tree
    void findLowestWeight()
    {
        int weight = _root->_value;
        _findLowestWeight(_root, weight);
        cout << "the lowest weight is : "<<weight << endl;
    }
    //functionality 9: find the first name in alphabetical order
    void findFirstAlphabetical()
    {
        Node* cur = _root;
        while(cur && cur->_left)
        {
            cur = cur->_left;
        }
        cout<<"the first alphabetical order name is : " << cur->_key<<endl;
    }
private:
    Node* _root;
    void _preOrder(Node* root)
    {
        if(!root)
            return;
        cout<<root->_key<<"->"<<root->_value<<" ";
        _preOrder(root->_left);
        _preOrder(root->_right);
    }
    void _inOrder(Node* root)
    {
        if(!root)
            return;
        _inOrder(root->_left);
        cout<<root->_key<<"->"<<root->_value<<" ";
        _inOrder(root->_right);
    }
    void _postOrder(Node* root)
    {
        if(!root)
            return;
        _postOrder(root->_left);
        _postOrder(root->_right);
        cout<<root->_key<<"->"<<root->_value<<" ";
    }
    int _findHeight(Node* root)
    {
        if(!root)
            return 0;
        int leftHeight = _findHeight(root->_left);
        int rightHeight = _findHeight(root->_right);
        return leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
    }
    
    int _findLeave(Node* root)
    {
        if(!root)
            return 0;
        if(root->_left == nullptr && root->_right == nullptr)
            return 1;
        int left = _findLeave(root->_left);
        int right = _findLeave(root->_right);
        return left + right;
    }
    
    Node* _find(const K& key, Node* root)
    {
        if(!root)
            return nullptr;
        if(key > root->_key)
            return _find(key, root->_right);
        else if(key < root->_key)
            return _find(key, root->_left);
        else
            return root;
    }
    void _findLowestWeight(Node* root, int& weight)
    {
        if(!root)
            return;
        if(root->_value < weight)
            weight = root->_value;
        _findLowestWeight(root->_left, weight);
        _findLowestWeight(root->_right, weight);
    }
};

int main() {
    string name;
    int weight;
    vector<pair<string, int>> vv;
    for(int i = 0; i < 15; i++)
    {
        cout<<"enter the "<< i+1 <<" name:\n";
        getline(cin, name);
        cout<<"enter the weight:\n";
        cin>>weight;
        cin.get();
        vv.push_back(make_pair(name, weight));
    }
    BinarySearchTree<string, int> bst(vv);
    cout<<"preorder printing:\n";
    bst.preOrder();
    cout<<"inorder printing:\n";
    bst.inOrder();
    cout<<"postorder printing\n";
    bst.postOrder();
    cout<<"enter the name you would like to search\n";
    getline(cin, name);
    bst.find(name);
    bst.findHeight();
    bst.findLeave();
    bst.findLowestWeight();
    bst.findFirstAlphabetical();
    return 0;
}


/*
 enter the 1 name:
 mark
 enter the weight:
 150
 enter the 2 name:
 tina
 enter the weight:
 115
 enter the 3 name:
 zach
 enter the weight:
 55
 enter the 4 name:
 amy
 enter the weight:
 140
 enter the 5 name:
 steve
 enter the weight:
 220
 enter the 6 name:
 brian
 enter the weight:
 250
 enter the 7 name:
 liz
 enter the weight:
 125
 enter the 8 name:
 anna
 enter the weight:
 220
 enter the 9 name:
 laura
 enter the weight:
 115
 enter the 10 name:
 alex
 enter the weight:
 175
 enter the 11 name:
 jason
 enter the weight:
 210
 enter the 12 name:
 eric
 enter the weight:
 175
 enter the 13 name:
 aaron
 enter the weight:
 195
 enter the 14 name:
 kim
 enter the weight:
 135
 enter the 15 name:
 brandon
 enter the weight:
 79
 preorder printing:
 mark->150 amy->140 alex->175 aaron->195 brian->250 anna->220 brandon->79 liz->125 laura->115 jason->210 eric->175 kim->135 tina->115 steve->220 zach->55
 inorder printing:
 aaron->195 alex->175 amy->140 anna->220 brandon->79 brian->250 eric->175 jason->210 kim->135 laura->115 liz->125 mark->150 steve->220 tina->115 zach->55
 postorder printing
 aaron->195 alex->175 brandon->79 anna->220 eric->175 kim->135 jason->210 laura->115 liz->125 brian->250 amy->140 steve->220 zach->55 tina->115 mark->150
 enter the name you would like to search
 jason
 the corresponding value is :210
 the height of the tree is : 7
 the tree have 6 leaves
 the lowest weight is : 55
 the first alphabetical order name is : aaron
 Program ended with exit code: 0
 */

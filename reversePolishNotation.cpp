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
    // a stack to maintain data
    Stack<float> st;
    for (int i = 0; i < token.size(); i++)
    {
        //convert data to float
        float tmp = atof(token[i].c_str());
        //if it is float number then push into stack
        if (tmp)
        {
            st.push(tmp);
        }
        //check if it is 0. and push into stack
        else if (strcmp(token[i].c_str(), "0") == 0)
        {
            st.push(0);
        }
        else
        {
            //check if the operator was wrong, exp: */
            if (token[i].size() > 1)
            {
                cout << "wrong operator.\n";
                throw;
            }
            float a = 0, b = 0, ret;
            //switch operator to each case. if no operator matched then throw error. 
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
                //check if divided by 0
                if (a == 0)
                {
                    cout << "divided by 0.\n";
                    throw;
                }
                st.pop();
                b = st.top();
                st.pop();
                ret = b / a;
                st.push(ret);
                break;
            default:
                cout << "wrong operator.\n";
                throw;
                break;
            }
        }
    }
    float retVal = st.top();
    st.pop();
    if (!st.empty())
    {
        cout << "too many variables.\n";
        throw;
    }
    return retVal;
}

int main()
{
    std::string str;
    while (getline(cin, str))
    {
        if (strcmp(str.c_str(), "0") == 0)
        {
            break;
        }
        cout << str << " = ";
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

/*
10 15 +
10 15 + = 25
10 15 -
10 15 - = -5
2.5 3.5 +
2.5 3.5 + = 6
0 10 /
0 10 / = 0
10 20 *
10 20 * = 200
-10 -30 -
-10 -30 - = 20
100 10 50 25 / * - -2 /
100 10 50 25 / * - -2 / = -40
0

D:\OneDrive\VSproject\Program 1 reverse polish\x64\Debug\Program 1 reverse polish.exe (process 1868) exited with code 0.
Press any key to close this window . . .
 
*/

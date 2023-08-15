vector<int> solution(vector<int> a) {
    int weight1 = 0, weight2 = 0;
    //0 1 2 3 4    5
 bool solution(int yourLeft, int yourRight, int friendsLeft, int friendsRight) {
    
    return min(yourLeft, yourRight) == min(friendsLeft , friendsRight) && max(yourLeft, yourRight) == max(friendsLeft , friendsRight);
}

    //0 1 2 3 4 5   
    //1 3 5 7 9
    //2 4 6 8 10
    for(int i = 0; i < a.size(); i += 2)
    {
        weight1 += a[i];
        if(i+1 != a.size())
            weight2 += a[i+1];
    }
    vector<int> ret;
    ret.push_back(weight1);
    ret.push_back(weight2);
    return ret;
}
bool solution(vector<int> a, vector<int> b) {
    int count = 0;    
    int idx1 = -1;
    int idx2 = -1;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i]!= b[i]){
            count++;
            if(idx1 == -1)
                idx1 = i;
            else
                idx2 = i;
        }
        if(count > 2)
            return false;
    }
    if(count == 1)
        return false;
    if(a[idx1] != b[idx2] || a[idx2] != b[idx1])
        return false;
    return true;

}

vector<string> solution(vector<string> picture) {
    string tmp(picture[0].length() + 2, '*');
    for(int i = 0; i < picture.size(); i++)
    {
        picture[i] = "*" + picture[i] + "*";
    }
    picture.insert(picture.begin(), tmp);
    picture.push_back( tmp);
    return picture;
}

string solution(string inputString) {
    //find last (
    //find first ) after last (
    int leftParenthese = inputString.find_last_of('(') + 1;
    while(leftParenthese != 0)
    {
        stringstream ss;
        int rightParenthese = inputString.find_first_of(')', leftParenthese);
        string str(rightParenthese-leftParenthese, ' ');
        reverse_copy(inputString.begin() + leftParenthese, inputString.begin()+rightParenthese, str.begin());
        ss<< inputString.substr(0, leftParenthese - 1) << str << inputString.substr(rightParenthese + 1);
        inputString = ss.str();
        leftParenthese = inputString.find_last_of('(') + 1;
    }
    return inputString;
}

vector<int> solution(vector<int> a) {
    multiset<int> st;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != -1)
            st.insert(a[i]);
    }
    auto it = st.begin();
    for(int i = 0; i < a.size(); i++)
    {
        if (a[i] == -1) {
            continue;
        }
        a[i] = *it;
        it++;
    }
    return a;
    // for(int i = 1; i < a.size(); i++)
    // {
    //     int key = a[i];
    //     if(key == -1)
    //         continue;
    //     for(int j = i - 1; j > 0; j--)
    //     {
    //         if(a[j] == -1)
    //             continue;
    //         if(key < a[j])
    //         {
    //             int t = a[j];
    //             a[j] = key;
    //             key = t;
    //         }
    //         else 
    //         {
    //             break;
    //         }
    //     }
    // }
    // return a;
}

bool solution(int n) {
    string str = to_string(n);
    int sum = 0;
    int idx = str.length() / 2;
    for(int i = 0; i < idx; i++)
    {
        sum += str[i] - '0';
        sum -= str[i + idx] - '0';
    }
    if(sum == 0)
        return true;
    else
        return false;
}

bool solution(int n) {
    string str = to_string(n);
    int sum = 0;
    int idx = str.length() / 2;
    for(int i = 0; i < idx; i++)
    {
        sum += str[i] - '0';
        cout<< sum << endl;
    }
    for(int i = idx; i < str.length(); i++)
    {
        sum -= str[i] - '0';  
        cout << sum << endl;
    }
    if(sum == 0)
        return true;
    else
        return false;
}


int solution(string s1, string s2) {
    unordered_map<char, int> mp;
    int count = 0;
    for(int i = 0; i < s1.size();i++)
    {
        mp[s1[i]]++;
    }
    for(int i = 0; i < s2.size();i++)
    {
        if(--mp[s2[i]] >= 0)
            count++;
    }
    return count;
}

int solution(vector<vector<int>> matrix) {
    int sum = 0;
    for(int j = 0; j < matrix[0].size(); j++)
    {
        for(int i = 0; i < matrix.size(); i++)
        {
            if(matrix[i][j] == 0)
                break;
            sum+= matrix[i][j];
        }
    }
    return sum;
}

int findFirstException(vector<int> sequence, int skip)
{
    for(int i = 0; i < sequence.size() - 1;i++)
    {
        if(i  == skip){
            continue;
        }
        if(i == skip - 1)
        {
            if(i+2 != sequence.size() && sequence[i+2] <= sequence[i])
                return i;
            continue;
        }
        else if(sequence[i+1] <= sequence[i])
        {
            return i;
        }
        
    }
    return -1;
}

bool solution(vector<int> sequence) {
    int idx = findFirstException(sequence,sequence.size());
    if(idx == -1)
        return true;
    else
    { 
        if(findFirstException(sequence, idx) == -1)
            return true;
        if(findFirstException(sequence, idx+1) == -1)
            return true;
    }
    return false;
}

bool cmp(const string& lhs, const string& rhs) {
   return lhs.length() > rhs.length();
}
 

vector<string> solution(vector<string> words, vector<string> parts) {
    vector<string> ret;
    sort(parts.begin(), parts.end(), cmp);
    for(int i = 0; i < words.size();i++)
    {
        int wordsIdx = -1;
        int partsIdx = -1;
        string str;
        for(int j = 0; j < parts.size(); j++)
        {
            if(partsIdx == -1)
            {
                int found = words[i].find(parts[j]);
                if(found != -1)
                {
                    wordsIdx = found;
                    partsIdx = j;
                }
            }
            else if(parts[partsIdx].length() > parts[j].length())
            {
                break;
            }
            else
            {
                int found = words[i].find(parts[j]);
                if(found != -1 && found < wordsIdx)
                {
                    wordsIdx = found;
                    partsIdx = j;
                }
            }
        }
        
        if(partsIdx == -1)
                ret.push_back(words[i]);
            else{
                str = words[i].substr(0, wordsIdx);
                str += "[";
                str += parts[partsIdx];
                str+= "]";
                str += words[i].substr(wordsIdx + parts[partsIdx].length());
                ret.push_back(str);
            }
    }
        return ret;

}

int test(Tree<int> * t, int& k)
{
    if(!t)
        return 0;
    int num = test(t->left, k);
    k--;
    cout<<k<<"->"<<t->value;
    if(k == 0)
        return t->value;
    return num + test(t->right, k);
}
int solution(Tree<int> * t, int k) {
    
    return test(t, k);
    // priority_queue<int,vector<int>, less<int>> q;
    // traverse(q, t, k);
    // int top = q.top();
    // while(!q.empty())
    // {
    //     q.pop();
    //     top = q.top();
    // }
    // return top;
}
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

bool isSame(Tree<int> * t1, Tree<int> * t2)
{
    if(t1 == nullptr && t2 == nullptr)
        return true;
    if(!t1)
        return false;
    if(!t2)
        return false;
    return t1->value == t2->value && isSame(t1->left, t2->left) && isSame(t1->right, t2->right);
}

bool solution(Tree<int> * t1, Tree<int> * t2) {
    if(!t2)
        return true;
    if(!t1)
        return false;
    
    if(isSame(t1, t2))
        return true;
    return solution(t1->left , t2)|| solution(t1->right, t2);
}


//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
vector<int> solution(Tree<int> * t) {
    vector<int> ret;
    if(!t)
        return ret;
    queue<Tree<int>*> q;
    q.push(t);
    while(!q.empty())
    {
        Tree<int>* tmp = q.front();
        q.pop();
        ret.push_back(tmp->value);
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }
    return ret;
}


string buildStr(string str, int idx, int root)
{
    if(idx == root)
    {
        return str;
    }
    if(root > idx)
        return "";
    if(str == "Engineer")
    {
        return buildStr("Engineer", idx, root * 2 + 1) + buildStr("Doctor", idx, root*2 + 2);
    }
    if(str == "Doctor")
    {
        return buildStr("Doctor", idx, root * 2 + 1) + buildStr("Engineer", idx, root*2 + 2);
    }
    
}

string solution(int level, int pos) {
    if(level == 1 && pos == 1)
        return "Engineer";
    int idx = pow(2, level - 1) - 2 + pos;
    return buildStr("Engineer", idx, 0);
}
// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * solution(ListNode<int> * l, int n) {
    if(n == 0)
        return l;
    ListNode<int> * fast = l;
    ListNode<int> * slow = l;
    for(int i = 0; i< n; i++)
    {
        fast = fast->next;
    }
    
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    if(!fast)
        return l;
    
    ListNode<int> * newHead = slow->next;
    slow->next = nullptr;
    fast->next = l;
    return newHead;
    
}

int solution(int n) {
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    return solution(n-1) + solution(n-2);
}

//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
int solution(vector<int> inputArray) {
    
    // vector<int> sum;
    int ret = inputArray[0];
    int sum = inputArray[0];
    for(int i = 1; i<inputArray.size();i++)
    {
        sum = inputArray[i] > sum + inputArray[i]? inputArray[i] : sum + inputArray[i];
        if(sum > ret)
            ret = sum;
    }
    return ret;
}

bool isSymmetry(Tree<int> * left, Tree<int> * right)
{
    if(left == nullptr && right == nullptr)
        return true;
    if(left == nullptr ||right == nullptr)
        return false;
    if(right->value != left->value)
        return false;
    return isSymmetry(left->left, right->right) && isSymmetry(left->right, right->left);
}

bool solution(Tree<int> * t) {
    if(!t)
        return true;
    return isSymmetry(t->left, t->right);
}



bool solution(vector<int> nums, int k) {
    map<int, int> mp;
    
    for(int i = 0; i < nums.size(); ++i)
    {
        if(mp.find(nums[i]) == mp.end())
        {
            mp[nums[i]] = i;
        }
        else {
            if(i - mp[nums[i]] <= k)
                return true;
            else
                mp[nums[i]] = i;
        }
    }
    return false;
}

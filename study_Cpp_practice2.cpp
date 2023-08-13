
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

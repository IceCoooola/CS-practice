//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root == nullptr) return res;

        if(root->left)
        {
            const vector<int> &left = postorderTraversal(root->left);
            res = std::move(left);
        }
        if(root->right)
        {
            const vector<int> &right = postorderTraversal(root->right);
            res.insert(res.end(), right.begin(), right.end());
        }
        res.push_back(root->val);
        return res;
    }
};

/* 栈，迭代做法 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(root == nullptr) return vector<int>();

        deque<int> res;
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();
            res.insert(res.begin(), node->val);
            if(node->left)
            {
                s.push(node->left);
            }
            if(node->right)
            {
                s.push(node->right);
            }
        }
        //vector<int> vec;
        //vec.reserve(res.size());
        //std::copy(res.begin(), res.end(), std::back_inserter(vec));
        //return vec;
        return vector<int>(res.begin(), res.end());
    }
};
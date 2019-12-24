/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* 递归 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root == nullptr) return res;

        res.push_back(root->val);
        if(root->left)
        {
            const vector<int> &left = preorderTraversal(root->left);
            res.insert(res.end(), left.begin(), left.end());
        }
        if(root->right)
        {
            const vector<int> &right = preorderTraversal(root->right);
            res.insert(res.end(), right.begin(), right.end());
        }
        return res;
    }
};

/* 栈 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root == nullptr) return res;

        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();
            res.push_back(node->val);
            if(node->right) s.push(node->right);    /* 左右子树交换位置 */
            if(node->left) s.push(node->left);
        }
        return res;
    }
};
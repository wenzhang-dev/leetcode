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
    vector<int> sequence;
public:
    void dfs(TreeNode *root)
    {
        if(root == nullptr) return;
        dfs(root->left);
        sequence.push_back(root->val);
        dfs(root->right);
    }

    int kthSmallest(TreeNode* root, int k) 
    {
        dfs(root);
        return sequence[k-1];
    }
};

/* 优化复杂度 */
class Solution {
    int res;
public:
    void dfs(TreeNode *root, int &k)
    {
        if(res != INT_MAX) return ;
        if(root->left) dfs(root->left, k);
        if(--k == 0) res = root->val;
        if(root->right) dfs(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) 
    {
        res = INT_MAX;
        dfs(root, k);
        return res;
    }
};
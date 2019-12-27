class Solution {
public:
    //dfs
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(root == nullptr) return false;
        if(root->left==nullptr && root->right==nullptr&&sum==root->val) return true;

        if(root->left && hasPathSum(root->left, sum-root->val)) return true;
        if(root->right && hasPathSum(root->right, sum-root->val)) return true;

        return false;
    }
};
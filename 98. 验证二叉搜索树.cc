/* 遍历时，需在上下界范围内 */
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    //preorder
    bool helper(TreeNode *root, long left, long right)
    {
        if(root == nullptr) return true;
        if(root->val <= left || root->val >= right) return false;
        return helper(root->left, left, root->val) && helper(root->right, root->val, right);
    }
};
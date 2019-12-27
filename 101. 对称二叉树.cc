class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        //中序遍历结果，前后对称：并不能确定一定对称
        return is_equal(root, root);
    }

    bool is_equal(TreeNode *left, TreeNode *right)
    {
        if(!left && !right) return true;
        if(!left || !right) return false;

        return left->val == right->val && 
               is_equal(left->left, right->right) && 
               is_equal(left->right, right->left);
    }
};
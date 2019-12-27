/* 先序遍历，依次比较元素是否相同 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(!p && !q) return true;
        else if((!p && q) || (p && !q)) return false;

        if(p->val != q->val)
            return false;
        if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) 
            return true;

        return false;
    }
};
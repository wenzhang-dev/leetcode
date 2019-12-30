/* 36ms, 25MB */
class Solution {
    int max, min;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        min = ::min(p->val, q->val);
        max = ::max(p->val, q->val);
        return dfs(root);
    }
    TreeNode* dfs(TreeNode* root)
    {
        if(max>root->val && min<root->val) return root;
        if(max==root->val && min<root->val) return root;
        if(min==root->val && max>root->val) return root;
        
        if(max < root->val)//左子树
        {
            return dfs(root->left);
        }
        if(min > root->val)//右子树
        {
            return dfs(root->right);
        }
        return nullptr;
    }
};

/* 可进一步简化 */
class Solution {
    int max, min;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        min = ::min(p->val, q->val);
        max = ::max(p->val, q->val);
        return dfs(root);
    }
    TreeNode* dfs(TreeNode* root)
    {
        if(max < root->val) return dfs(root->left);
        if(min > root->val) return dfs(root->right);
        return root;
    }
};
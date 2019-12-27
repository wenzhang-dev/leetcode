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
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr) return true;

        /* 根节点是否平衡 */
        int left = treeDepth(root->left);
        int right = treeDepth(root->right);
        if(abs(left-right) > 1) return false;
        
        /* 左右子树是否平衡 */
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int treeDepth(TreeNode *root)
    {
        if(root == nullptr) return 0;

        int left = treeDepth(root->left);   /* 左子树高度 */
        int right = treeDepth(root->right); /* 右子树高度 */
        return left>right?left+1:right+1;   /* 当前节点高度 */
    }
};

/* 上诉算法缺点，多次计算同一个节点的高度 */
class Solution {
    unordered_map<TreeNode *, int> umap;
public:
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr) return true;

        /* 根节点是否平衡 */
        int left = treeDepth(root->left);
        int right = treeDepth(root->right);
        if(abs(left-right) > 1) return false;
        
        /* 左右子树是否平衡 */
        return isBalanced(root->left) && isBalanced(root->right);
    }

    /* 记忆法优化计算 */
    int treeDepth(TreeNode *root)
    {
        if(root == nullptr) return 0;
        if(umap[root] != 0) return umap[root];

        int left=0, right=0;
        if(umap[root->left] != 0) left = umap[root->left];
        else {
            left = treeDepth(root->left);
             umap[root->left] = left;
        }
        if(umap[root->right] != 0) right = umap[root->right];
        else {
            right = treeDepth(root->right);
            umap[root->right] = right;
        }
        int curDepth = left>right?left+1:right+1;
        umap[root] = curDepth;
        return curDepth;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr) return true;
        int depth = 0;
        /* 后序遍历优化求值 */
        /* 在判断是否为平衡二叉树时，左右子树高度先求得了 */
        return dfs(root, depth); 
    }

    bool dfs(TreeNode *root, int &depth)
    {
        if(root == nullptr) 
        {
            depth = 0;
            return true;
        }

        int left, right;
        if(dfs(root->left, left) && dfs(root->right, right))
        {
            if(abs(left - right) > 1) return false;
            depth = left>right?left+1:right+1;
            return true;
        }
        return false;
    }

};
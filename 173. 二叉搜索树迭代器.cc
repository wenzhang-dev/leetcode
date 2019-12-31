/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    vector<int> sequece;
    int index;

    void dfs(TreeNode *root)
    {
        if(root == nullptr) return ;
        dfs(root->left);
        sequece.push_back(root->val);
        dfs(root->right);
    }
public:
    BSTIterator(TreeNode* root) 
    {
        index = 0;
        dfs(root);
    }
    
    /** @return the next smallest number */
    int next() 
    {
        return sequece[index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return index < sequece.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 
/* 优化空间复杂度 */
class BSTIterator {
    stack<TreeNode *> sta;
    TreeNode *cur;
public:
    BSTIterator(TreeNode* root) : cur(root)
    {}
    
    /** @return the next smallest number */
    int next() 
    {
        int res;
        //左子树
        while(cur != nullptr)
        {
            sta.push(cur);
            cur = cur->left;
        }
        //父节点
        cur = sta.top(); sta.pop();
        res = cur->val;
        //右子树
        cur = cur->right;

        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return cur!=nullptr || !sta.empty();
    }
};

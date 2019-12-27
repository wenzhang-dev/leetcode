class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        if(root == nullptr) return res;
        dfs(root, sum, vector<int>());
        return res;
    }

    /* path最好不用引用，保证每次递归时，都是独立的副本 */
    void dfs(TreeNode *root, int sum, vector<int> path)
    {
        path.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && sum==root->val)
        {
            res.push_back(std::move(path));
            return ;
        }

        if(root->left) dfs(root->left, sum-root->val, path);
        if(root->right) dfs(root->right, sum-root->val, path);
    }
};

/* 优化 */
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        if(root == nullptr) return res;
        vector<int> subRes;

        dfs(root, sum, subRes);
        return res;
    }

    /* 优化:将path改为引用，效果不理想 */
    void dfs(TreeNode *root, int sum, vector<int> &path)
    {
        path.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && sum==root->val)
        {
            res.push_back(path);
            return ;
        }

        if(root->left) 
        {
            dfs(root->left, sum-root->val, path);
            path.pop_back();
        }
        if(root->right)
        {
             dfs(root->right, sum-root->val, path);
             path.pop_back();
        }
    }
};
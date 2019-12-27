class Solution {
    vector<string> res;
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if(root == nullptr) return res;
        dfs(root, "");
        return res;
    }

    /* 前序 */
    void dfs(TreeNode *root, string path)
    {
        /* 叶子节点 */
        if(root->left == nullptr && root->right == nullptr)
        {
            path += to_string(root->val);
            res.push_back(std::move(path));
            return ;
        }

        path += to_string(root->val) + "->";
        if(root->left) dfs(root->left, path);
        if(root->right) dfs(root->right, path);
    }
};
class Solution {
    vector<int> subRes;
public:
    int sumNumbers(TreeNode* root) 
    {
        if(root == nullptr) return 0;
        dfs(root, 0);

        int sum = 0;
        for(int num : subRes) sum += num;
        return sum; 
    }

    void dfs(TreeNode *root, int sum)
    {
        //叶子节点
        if(root->left==nullptr && root->right==nullptr)
        {
            subRes.push_back(sum*10+root->val);
            return ;
        }
        if(root->left) dfs(root->left, sum*10+root->val);
        if(root->right) dfs(root->right, sum*10+root->val);
    }
};

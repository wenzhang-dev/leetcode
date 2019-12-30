/* 错误示例：[1,2,3,4]，预期结果应该为[1,3,4] */
/* 不能仅仅遍历右子树 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;
        if(root == nullptr) return res;
        dfs(root, res);
        return res;
    }

    //preorder
    /* 优先遍历右子树，当右子树不存在时，遍历左子树 */
    void dfs(TreeNode *root, vector<int> &res)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            res.push_back(root->val);
            return ;
        }
        res.push_back(root->val);
        if(root->right)
        {
            dfs(root->right, res);
        } 
        else if(root->left)
        {
            dfs(root->left, res);
        }
    }
};

/* bfs，取每层遍历的最右边元素 */
/* 4ms */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;
        if(root == nullptr) return res;
        queue<TreeNode *> que;
        que.push(root);

        int size;
        while((size = que.size()) != 0)
        {
            TreeNode *node;
            for(int i=0; i<size; ++i)
            {
                node = que.front(); que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(node->val);
        }

        return res;
    }
};
/* 错误示例：[4,1,null,2,null,3]，预期结果为7 */
/* 使用层次遍历，并不是正确解 */
class Solution {
public:
    int rob(TreeNode* root) 
    {
        if(root == nullptr) return 0;
        queue<TreeNode *> que;
        que.push(root);

        int res[2] = {0}, idx = 0;
        int size;
        while((size = que.size()) != 0)
        {
            for(int i=0; i<size; ++i)
            {
                TreeNode *node = que.front(); que.pop();
                res[idx] += node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            idx==0?idx=1:idx=0;
        }
        return max(res[0], res[1]);
    }
};

/* 超出时间限制 */
/* 根据相邻节点不能同时偷，写出递归式 */
class Solution {
public:
    int rob(TreeNode* root) 
    {
        if(root == nullptr) return 0;

        int money = root->val;
        if(root->left)
        {
            money += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right)
        {
            money += rob(root->right->left) + rob(root->right->right);
        }
        return max(money, rob(root->left)+rob(root->right));
    }
};

/* 记忆法 */
/* 二叉树使用hashmap来记忆前面计算的值 */
class Solution {
public:
    int rob(TreeNode* root) 
    {
        unordered_map<TreeNode *, int> umap;
        return helper(umap, root);
    }

    int helper(unordered_map<TreeNode *, int> &umap, TreeNode *root)
    {
        if(root == nullptr) return 0;
        if(umap.find(root) != umap.end()) return umap[root];
        
        int money = root->val;
        if(root->left)
        {
            money += helper(umap, root->left->left) + helper(umap, root->left->right);
        }
        if(root->right)
        {
            money += helper(umap, root->right->left) + helper(umap, root->right->right);
        }

        int maxMoney = max(money, helper(umap, root->left)+helper(umap, root->right));
        umap[root] = maxMoney;
        return maxMoney;
    }
};

/* 动态规划 */
class Solution {
public:
    int rob(TreeNode* root) 
    {
        int res[2];
        helper(root, res);
        return max(res[0], res[1]);
    }

    void helper(TreeNode *root, int *res)
    {
        if(root == nullptr) 
        {
            res[0] = res[1] = 0;
            return;
        }
        int left[2], right[2];
        helper(root->left, left);
        helper(root->right, right);

        res[0] = max(left[0], left[1]) + max(right[0], right[1]); /* 当前节点不偷 */
        res[1] = root->val + right[0] + left[0]; /* 当前节点偷 */
    }
};

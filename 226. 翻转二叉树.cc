class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == nullptr) return nullptr;

        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);

        root->left = right;
        root->right = left;
        return root;
    }
};

/* bfs */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == nullptr) return nullptr; 
        //bfs, 遍历每个父节点时，将子节点交换
        queue<TreeNode *> que;
        que.push(root);
        
        while(!que.empty())
        {
            TreeNode *node = que.front(); que.pop();
            swap(node->right, node->left);
            if(node->right) que.push(node->right);
            if(node->left) que.push(node->left);
        }
        return root;
    }
};

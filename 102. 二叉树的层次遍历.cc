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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root == nullptr) return res;

        std::queue<TreeNode *> qtree;
        qtree.push(root);

        vector<int> subRes;
        while(!qtree.empty())
        {
            int size = qtree.size();
            subRes.clear();
            for(int i=0; i<size; ++i)
            {
                TreeNode *node = qtree.front();
                qtree.pop();
                subRes.push_back(node->val);
                if(node->left) qtree.push(node->left);
                if(node->right) qtree.push(node->right);
            }
            res.push_back(subRes);
        }
        return res;
    }
};
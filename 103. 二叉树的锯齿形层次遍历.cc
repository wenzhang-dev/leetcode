/* bfs: 4ms, 13MB */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root == nullptr) return res;

        queue<TreeNode *> que;
        que.push(root);

        int size;
        deque<int> subRes;
        bool direction = true;
        while((size = que.size()) != 0)
        {
            subRes.clear();
            for(int i=0; i<size; ++i)
            {
                TreeNode *node = que.front(); que.pop();
                if(direction) subRes.push_back(node->val);
                else subRes.push_front(node->val); 

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            vector<int> tmp(subRes.begin(), subRes.end());
            res.emplace_back(tmp);
            direction?direction=false:direction=true;
        }
        return res;
    }
};


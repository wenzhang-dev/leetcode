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
    vector<int> inorder_;
    vector<int> postorder_;
    unordered_map<int, int> umap_;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int size = inorder.size();
        for(int i=0; i<size; ++i)
        {
            umap_[inorder[i]] = i;
        }
        inorder_ = std::move(inorder);
        postorder_ = std::move(postorder);

        return helper(0, size, 0, size);
    }

    TreeNode *helper(int istart, int iend, int pstart, int pend)
    {
        if(istart >= iend || pstart >= pend) return nullptr;

        int rootVal = postorder_[pend-1];
        int rootIdx = umap_[rootVal];

        TreeNode *root = new TreeNode(rootVal);
        root->left = helper(istart, rootIdx, pstart, pstart+(rootIdx-istart));
        root->right = helper(rootIdx+1, iend, pstart+(rootIdx-istart), pend-1);

        return root;
    }
};

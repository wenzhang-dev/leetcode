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
    unordered_map<int, int> umap_; //element->index
    vector<int> preorder_;
    vector<int> inorder_;
    int preIdx_ = 0;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        /* 树中无重复元素，可以使用hashmap确定元素位置 */
        for(int i=0; i<inorder.size(); ++i) 
        {
            umap_[inorder[i]] = i;
        }
        preorder_ = std::move(preorder);
        inorder_ = std::move(inorder);
        
        return helper(0, inorder_.size());
    }

    TreeNode *helper(int istart, int iend)
    {
        if(istart == iend) return nullptr;

        int rootVal = preorder_[preIdx_++];
        int rootIdx = umap_[rootVal];

        TreeNode *root = new TreeNode(rootVal);
        root->left = helper(istart, rootIdx);   /* 左子树 */
        root->right = helper(rootIdx+1, iend);  /* 右子树 */

        return root;
    }
};
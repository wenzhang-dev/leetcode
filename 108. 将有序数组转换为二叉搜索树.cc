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
    vector<int> nums_;

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        nums_ = std::move(nums);
        return buildSubtree(0, nums_.size());
    }

    TreeNode *buildSubtree(int start, int end)
    {
        if(start >= end) return nullptr;

        int mid = start + (end-start)/2;

        TreeNode *root = new TreeNode(nums_[mid]);
        root->left = buildSubtree(start, mid);
        root->right = buildSubtree(mid+1, end);

        return root;
    }
};
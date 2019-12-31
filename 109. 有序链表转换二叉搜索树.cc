/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head == nullptr) return nullptr;

        vector<int> elem;
        while(head != nullptr)
        {
            elem.push_back(head->val);
            head = head->next;
        }

        /* 2分法 */
        return helper(elem, 0, elem.size());
    }

    TreeNode *helper(vector<int> &elem, int up, int down)
    {
        if(up == down) return nullptr;
        int mid = up+(down-up)/2;
        if(mid == up) return new TreeNode(elem[mid]);

        TreeNode *root = new TreeNode(elem[mid]);
        root->left = helper(elem, up, mid);
        root->right = helper(elem, mid+1, down);
        return root;
    }
};
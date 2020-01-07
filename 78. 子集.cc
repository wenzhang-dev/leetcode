class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res;
        backtrace(nums, 0, res, vector<int>());
        return res;
    }
    //回溯法
    //使用递归的方法，搜索所有可行解
    void backtrace(vector<int> &nums, int index, vector<vector<int>> &res, vector<int> subres)
    {
        res.push_back(subres);
        for(int i=index; i<nums.size(); ++i)
        {
            subres.push_back(nums[i]);
            backtrace(nums, i+1, res, subres);
            subres.pop_back();
        }
    }
};
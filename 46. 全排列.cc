class Solution {
    vector<vector<int>> res;
    vector<int> path;

public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        backtrace(nums);
        return res;
    }

    void backtrace(vector<int> &nums)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return ;
        }

        for(int i=0; i<nums.size(); ++i)
        {
            //去重
            if(find(path.begin(), path.end(), nums[i]) != path.end()) continue;

            path.push_back(nums[i]);
            backtrace(nums);
            path.pop_back();
        }
    }
};
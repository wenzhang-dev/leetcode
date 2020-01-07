class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        map<string, multiset<int>> memo;
        backtrace(nums, 0, memo, multiset<int>());

        vector<vector<int>> res;
        for(auto &elem : memo)
        {
            vector<int> tmp;
            for(auto num : elem.second)
            {
                tmp.push_back(num);
            }
            res.push_back(std::move(tmp));
        }
        return res;
    }

    void backtrace(vector<int>& nums, int index, map<string, multiset<int>> &memo, multiset<int> subres)
    {
        string idStr;
        for(auto num : subres) idStr+=to_string(num);/* 将数组中的数字串成字符串，用于去重 */
        memo[idStr] = subres;

        for(int i=index; i<nums.size(); ++i)
        {
            auto iter = subres.insert(nums[i]);
            backtrace(nums, i+1, memo, subres);
            subres.erase(iter);
        }
    }
};

/* 优化 */
/* 排序用于去重 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); /* 排序 */
        backtrace(nums, 0, res, vector<int>());
        return res;
    }

    void backtrace(vector<int>& nums, int index, vector<vector<int>> &res, vector<int> subres)
    {
        res.push_back(subres);
        for(int i=index; i<nums.size(); ++i)
        {
            if(i>index && nums[i] == nums[i-1]) continue;

            subres.push_back(nums[i]);
            backtrace(nums, i+1, res, subres);
            subres.pop_back();
        }
    }
};
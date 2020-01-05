class Solution {
public:
    int rob(vector<int>& nums) 
    {
        //dp[i] : 前i个房间能偷到的最高金额
        //dp[i] = max(dp[i-1], dp[i-2]+A[i])
        //dp[i+1] = max(dp[i], dp[i-1]+A[i+1])
        //由于第1个房间和最后一个房间不能同时抢，可分为两种情况来处理
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        return max(helper(vector<int>(nums.begin(), nums.end()-1)), 
                   helper(vector<int>(nums.begin()+1, nums.end())));
    }

    int helper(const vector<int> &nums)
    {
        int cur = 0, prev = 0, tmp;
        for(const auto num : nums)
        {
            tmp = cur;
            cur = max(cur, prev + num);
            prev = tmp;
        }
        return cur;
    }
};

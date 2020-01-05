/* 动态规划：4ms */
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        // dp[i] : 表示前i个房间能偷盗的最高金额
        // dp[0] = 0, dp[1] = nums[0], dp[2] = max(nums[0], nums[1])
        // dp[3] = max(num[1], num[0]+num[3])
        // dp[i] = max(nums[i]+dp[i-2], dp[i-1])
        vector<int> dp(nums.size()+1);
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]); //dp[2] = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); ++i)
        {
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        
        return dp[nums.size()-1];
    }
};
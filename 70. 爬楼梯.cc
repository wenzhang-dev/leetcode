//递归式
class Solution {
public:
    int climbStairs(int n) 
    {
        return helper(0, n);
    }
    int helper(int cur, int obj)
    {
        if(cur > obj) return 0;
        if(cur == obj) return 1;
        return helper(cur+1, obj) + helper(cur+2,obj); //O(2^n)
    }
};

/* 优化时间复杂度 */
/* 记忆法:0ms, 8.6MB */
class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> subRes(n+1, 0);
        return helper(0, n, subRes);
    }
    int helper(int cur, int obj, vector<int> &v)
    {
        if(cur > obj) return 0;
        if(cur == obj) return 1;
        
        if(v[cur] != 0) return v[cur];
        int res = helper(cur+1, obj, v) + helper(cur+2,obj, v); //O(2^n)
        v[cur] = res;
        return res;
    }
};

/* 动态规划 */
class Solution {
public:
    /* dp[i] = dp[i-1] + dp[i-2] */
    /* dp[i]: 爬第i层，有多少种爬法 */
    int climbStairs(int n) 
    {
        if(n == 1) return 1;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; ++i) 
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
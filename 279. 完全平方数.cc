class Solution {
public:
    //dp[i] = min(dp[i], dp[i-j*j]+1)
    int numSquares(int n)
    {
        vector<int> dp(n+1);
        for(int i=1; i<=n; ++i)
        {
            dp[i] = i;//最坏情况
            for(int j=0; i-j*j>=0; ++j)
            {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
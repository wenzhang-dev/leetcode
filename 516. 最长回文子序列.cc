class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int n = s.size();
        //dp[i][j] : 代表字符串第i个位置到第j个位置最长回文长度
        // 0 1 2 ... i-1 i ... j-1 j j+1 ... n-1 -> 0<=i<=j<=n-1
        //if(s[i-1] == s[j-1]) dp[i-1][j+1] = dp[i][j]+2
        //否则 dp[i-1][j+1] = max(dp[i-1][j], dp[i][j+1])

        //dp[i][j] = 2+dp[i+1][j-1]
        //dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i=n-1; i>=0; --i)
        {
            dp[i][i] = 1;
            for(int j=i+1; j<n; ++j)
            {
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};

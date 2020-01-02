/* 递归法 */
/* 超时 */
class Solution {
    int m_, n_;
public:
    int uniquePaths(int m, int n) 
    {
        m_ = m; n_ = n;
        return helper(1, 1);
    }
    int helper(int x, int y)
    {
        if(x > n_ || y > m_) return 0;
        if(x == n_ && y == m_) return 1;

        return helper(x+1, y) + helper(x, y+1);
    }
};

/* 记忆法 */
/* 通过，8ms */
class Solution {
    int m_, n_;
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> subRes(m+1, vector<int>(n+1, 0));
        m_ = m; n_ = n;
        return helper(1, 1, subRes);
    }
    int helper(int x, int y, vector<vector<int>> &v)
    {
        if(x > n_ || y > m_) return 0;
        if(x == n_ && y == m_) return 1;

        if(v[y][x] != 0) return v[y][x];
        v[y][x] = helper(x+1, y, v) + helper(x, y+1, v);
        return v[y][x];
    }
};

/* 动态规划 */
/* 递归式: dp(i,j) = dp(i-1, j) + dp(i, j-1) */
/* 4ms, 8.7MB */
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        if(m==0 || n==0) return 1;  /* 只能向右或向下移动 */
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(i==0 || j==0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

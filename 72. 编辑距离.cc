/* 动态规划 */
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        //dp[i][j] : word1中前i个字符转换成word2前j个字符的最小操作次数 
        //dp[i][j] = dp[i-1][j-1]; word1[i] == word2[j], 无需额外操作
        //dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])+1; word1[i]!=word2[j] 分别执行替换、插入和删除
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        //赋初值
        for(int i=1; i<=word1.size(); ++i) dp[i][0] = dp[i-1][0] + 1;    //删除
        for(int i=1; i<=word2.size(); ++i) dp[0][i] = dp[0][i-1] + 1;    //增加

        for(int i=1; i<=word1.size(); ++i)
        {
            for(int j=1; j<=word2.size(); ++j)
            {
                if(word1[i-1] != word2[j-1])
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                else
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[word1.size()][word2.size()];
    }
};


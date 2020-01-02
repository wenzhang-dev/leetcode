/* 递归法超时 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        if(triangle.size() == 1) return triangle[0][0];
        return dfs(triangle, 1, 0, triangle[0][0]);
    }
    //返回最小值
    int dfs(vector<vector<int>> &triangle, int level, int index, int sum)
    {
        if(level == triangle.size()-1)
        {
            return min(sum+triangle[level][index], sum+triangle[level][index+1]);
        }

        return min(dfs(triangle, level+1, index, sum+triangle[level][index]),
                   dfs(triangle, level+1, index+1, sum+triangle[level][index+1]));
    }
};

           |= triangle[n-1,c]       if n-1 is the last row. 
f(n-1, c) -|
           |= min{f(n,c) + triangle[n-1,c], f(n,c+1) + triangle[n-1,c]}

class Solution {
public:
    /* 从下向上求和 */
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<int> dp(triangle.back());
        for(int i=triangle.size()-2; i>=0; --i)
        {
            for(int j=0; j<i+1; ++j)
            {
                dp[j] = min(dp[j]+triangle[i][j], dp[j+1]+triangle[i][j]);
            }
        }
        return dp[0];
    }
};
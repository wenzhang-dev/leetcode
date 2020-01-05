/* 递归法：暴力法 */
class Solution {
    int row, col;
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        row = grid.size(); col = grid[0].size();
        return helper(grid, 0, 0, 0);   //最小路径和
    }
    //dfs
    int helper(vector<vector<int>> &grid, int x, int y, int sum)
    {
        if(x>=col || y>=row) return INT_MAX;
        if(x==col-1 && y==row-1) return sum+grid[y][x];

        return min(helper(grid, x+1, y, sum+grid[y][x]), helper(grid, x, y+1, sum+grid[y][x]));
    }
};

/* 记忆法：由不同路径到达的相同的点，其路径和可能不同 */
/* 所以，不能使用前面计算好的值，每次都得计算 */
/* 记忆法失效 */

/* 动态规划 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int row = grid.size(), col = grid[0].size();
        //dp[i][j] : 以(0,0)到达(i,j)路径和得最小值
        vector<vector<int>> dp(row, vector<int>(col));
		//初始化dp[0][i] 0<=i<col; dp[j][0] 0<=j<row
        for(int i=0, sum=0; i<col; ++i) 
        {
            sum += grid[0][i];
            dp[0][i] = sum;
        }
        for(int i=0, sum=0; i<row; ++i)
        {
            sum += grid[i][0];
            dp[i][0] = sum;
        }
        
        for(int i=1; i<row; ++i)
        {
            for(int j=1; j<col; ++j)
            {
                dp[i][j] = min(dp[i-1][j]+grid[i][j], dp[i][j-1]+grid[i][j]);
            }
        
        }
        return dp[row-1][col-1];
    }

};
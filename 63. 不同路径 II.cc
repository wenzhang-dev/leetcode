/* 记忆法 */
/* 超时 */
class Solution {
    int m, n;   //m*n
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        m = obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>> vi(m, vector<int>(n));
        return helper(0, 0,obstacleGrid, vi);
    }

    int helper(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &visited)
    {
        if(x>n-1 || y>m-1 || grid[y][x]) return 0;
        if(x==n-1 && y==m-1) return 1;
        if(visited[y][x] != 0) return visited[y][x];

        visited[y][x] = helper(x+1, y, grid, visited) + helper(x, y+1, grid, visited);
        return visited[y][x];
    }
};

/* 动态规划 */
/* 8ms */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if(obstacleGrid[0][0] == 1) return 0;
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<long>> visit(row, vector<long>(col));

        visit[0][0] = 1;obstacleGrid[0][0] = 1;
        for(int i=1; i<col; ++i)
        {
            visit[0][i] = (obstacleGrid[0][i]==0 && obstacleGrid[0][i-1]==1)?1:0;
            obstacleGrid[0][i] = visit[0][i];
        }
        for(int i=1; i<row; ++i)
        {
            visit[i][0] = (obstacleGrid[i][0]==0 && obstacleGrid[i-1][0]==1)?1:0;
            obstacleGrid[i][0] = visit[i][0];
        }

        for(int i=1; i<row; ++i)
        {
            for(int j=1; j<col; ++j)
            {
                if(obstacleGrid[i][j]!=0) visit[i][j]=0;
                else visit[i][j] = visit[i-1][j] + visit[i][j-1];
            }
        }
        return visit[row-1][col-1];
    }
};
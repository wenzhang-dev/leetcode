class Solution {
    int row_;
    int col_;

public:
    /* 递归法 */
    void dfs(vector<vector<char>> &grid, int row, int col)
    {
        grid[row][col] = '0';

        if(row-1>=0 && grid[row-1][col] == '1') dfs(grid, row-1, col);
        if(col-1>=0 && grid[row][col-1] == '1') dfs(grid, row, col-1);
        if(row+1<row_ && grid[row+1][col] == '1') dfs(grid, row+1, col);
        if(col+1<col_ && grid[row][col+1] == '1') dfs(grid, row, col+1);
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        row_ = grid.size();
        if(row_ == 0) return 0;
        col_ = grid[0].size();

        int number = 0;
        for(int i=0; i<row_; ++i)
        {
            for(int j=0; j<col_; ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++number;
                    dfs(grid, i, j);
                }
            }
        }
        return number;
    }
};

/* bfs */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();

        queue<pair<int, int>> que;
        int number = 0;
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++number;
                    grid[i][j] = '0';
                    que.push(make_pair(i, j));
                    while(!que.empty())
                    {
                        int x = que.front().first;
                        int y = que.front().second;
                        que.pop();
                        if(x-1>=0 && grid[x-1][y] == '1')
                        {
                            que.push(make_pair(x-1, y));
                            grid[x-1][y] = '0';
                        }
                        if(y-1>=0 && grid[x][y-1] == '1')
                        {
                            que.push(make_pair(x, y-1));
                            grid[x][y-1] = '0';
                        }
                        if(x+1<row && grid[x+1][y] == '1')
                        {
                            que.push(make_pair(x+1, y));
                            grid[x+1][y] = '0';
                        }
                        if(y+1<col && grid[x][y+1] == '1')
                        {
                            que.push(make_pair(x, y+1));
                            grid[x][y+1] = '0';
                        }
                    }

                }
            }
        }
        return number;
    }
};

/* bfs超时 */
class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int row = board.size();
        if(row == 0) return ;
        int col = board[0].size();

        queue<pair<int, int>> que;
        vector<pair<int, int>> vec;
        vector<vector<bool>> isAccess;
        bool isFilled = false;

        for(int i=0; i<row; ++i) isAccess.push_back(vector<bool>(col, false));

        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(!isAccess[i][j] && board[i][j] == 'O')
                {
                    vec.clear();
                    que.push(make_pair(i, j));
                    isFilled = true;
                    while(!que.empty())
                    {
                        int x = que.front().first;
                        int y = que.front().second;
                        if(x==0 || x==row-1 || y==0 || y==col-1) isFilled = false;
                        que.pop();
                        isAccess[x][y] = true;
                        if(isFilled) vec.push_back(make_pair(x, y));

                        if(x-1>=0 && !isAccess[x-1][y] && board[x-1][y] == 'O') que.push(make_pair(x-1, y));
                        if(y-1>=0 && !isAccess[x][y-1] && board[x][y-1] == 'O') que.push(make_pair(x, y-1));
                        if(x+1<row && !isAccess[x+1][y] && board[x+1][y] == 'O') que.push(make_pair(x+1, y));
                        if(y+1<col && !isAccess[x][y+1] && board[x][y+1] == 'O') que.push(make_pair(x, y+1));
                    }

                    /* fill grids */
                    if(isFilled)
                    {
                        for_each(vec.begin(), vec.end(), [&](pair<int, int> &point){
                            board[point.first][point.second] = 'X';
                        });
                    }
                }
            }
        }
    }
};

/* bfs， 每次仅仅从边沿开始遍历 */
/* 超时 */
class Solution {
    int row_;
    int col_;

public:
    void bfs(vector<vector<char>> &board, int i, int j)
    {
        queue<pair<int, int>> que;
        que.push(make_pair(i, j));
        while(!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            board[x][y] = '#';
            
            if(x-1>=0 && board[x-1][y]=='O') que.push(make_pair(x-1, y));
            if(y-1>=0 && board[x][y-1]=='O') que.push(make_pair(x, y-1));
            if(x+1<row_ && board[x+1][y]=='O') que.push(make_pair(x+1, y));
            if(y+1<col_ && board[x][y+1]=='O') que.push(make_pair(x, y+1));
        }
    }

    void solve(vector<vector<char>>& board) 
    {
        int row_ = board.size();
        if(row_ == 0) return ;
        int col_ = board[0].size();

        for(int i=0; i<row_; ++i)
        {
            for(int j=0; j<col_; ++j)
            {
                bool isEdge = (i==0 || i==row_-1 || j==0 || j==col_-1);
                if(isEdge && board[i][j] == 'O')
                {
                    bfs(board, i, j);
                }
            }
        }

        for(int i=0; i<row_; ++i)
        {
            for(int j=0; j<col_; ++j)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};

/* 超时 */
class Solution {
    int row_;
    int col_;

    struct Point
    {
        int x;
        int y;
        Point(int i, int j):x(i), y(j){}
    };

public:
    void bfs(vector<vector<char>> &board, int i, int j)
    {
        queue<Point> que;
        que.push(Point(i, j));
        while(!que.empty())
        {
            Point cur = que.front();
            int x = cur.x;
            int y = cur.y;
            que.pop();
            board[x][y] = '#';
            
            if(x-1>=0 && board[x-1][y]=='O') que.push(Point(x-1, y));
            if(y-1>=0 && board[x][y-1]=='O') que.push(Point(x, y-1));
            if(x+1<row_ && board[x+1][y]=='O') que.push(Point(x+1, y));
            if(y+1<col_ && board[x][y+1]=='O') que.push(Point(x, y+1));
        }
    }

    void solve(vector<vector<char>>& board) 
    {
        row_ = board.size();
        if(row_ == 0) return ;
        col_ = board[0].size();
        
        for(int i=0; i<row_; ++i)
        {
            for(int j=0; j<col_; ++j)
            {
                bool isEdge = (i==0 || i==row_-1 || j==0 || j==col_-1);
                if(isEdge && board[i][j] == 'O')
                {
                    bfs(board, i, j);
                }
            }
        }
        
        for(int i=0; i<row_; ++i)
        {
            for(int j=0; j<col_; ++j)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};

/* dfs: 40ms */
class Solution {
    int row_;
    int col_;

public:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if(i<0||j<0||i>=row_||j>=col_||board[i][j]=='#'||board[i][j]=='X') return ;

        board[i][j] = '#';

        dfs(board, i-1, j);
        dfs(board, i, j-1);
        dfs(board, i+1, j);
        dfs(board, i, j+1);
    }

    void solve(vector<vector<char>>& board) 
    {
        row_ = board.size();
        if(row_ == 0) return ;
        col_ = board[0].size();
        
        for(int i=0; i<row_; ++i)
        {
            for(int j=0; j<col_; ++j)
            {
                bool isEdge = (i==0 || i==row_-1 || j==0 || j==col_-1);
                if(isEdge && board[i][j] == 'O')
                {
                    dfs(board, i, j);
                }
            }
        }
        
        for(int i=0; i<row_; ++i)
        {
            for(int j=0; j<col_; ++j)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
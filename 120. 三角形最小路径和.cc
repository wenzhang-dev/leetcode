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


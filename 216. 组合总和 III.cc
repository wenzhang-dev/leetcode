class Solution {
    int k, n;
    vector<vector<int>> res;
    vector<int> path;

public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        this->k = k; this->n = n;
        backtrace(1, 0);
        return res;
    }

    void backtrace(int index, int sum)
    {
        if(sum == n)
        {
            if(path.size() == k) res.push_back(path);
            return ;
        }
        /* 回溯+剪枝 */
        for(int i=index; i<=9 && i+sum<=n && path.size()<k; ++i)
        {
            path.push_back(i);
            backtrace(i+1, i+sum);/* 不能包含重复元素 */
            path.pop_back();
        }
    }
};
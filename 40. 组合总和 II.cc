class Solution {
    vector<vector<int>> res;
    int target;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        this->target = target;
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, vector<int>(), 0, 0);
        return res;
    }

    void backtrace(vector<int> &candidates, vector<int> subres, int index, int sum)
    {
        if(sum == target)
        {
            res.push_back(move(subres));
            return ;
        }

        for(int i=index; i<candidates.size() && sum+candidates[i]<=target; ++i)
        {
            /* 在同层递归中，对于重复元素，不再决策，直接跳过 */
            if(i>index && candidates[i] == candidates[i-1]) continue;

            subres.push_back(candidates[i]);
            backtrace(candidates, subres, i+1, sum+candidates[i]);
            subres.pop_back();
        }
    }
};

/* 优化 */
class Solution {
    vector<vector<int>> res;
    vector<int> path;	/* 使用一个数组，backtrace参数不再使用subres */
    int target;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        this->target = target;
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, 0, 0);
        return res;
    }

    void backtrace(vector<int> &candidates, int index, int sum)
    {
        if(sum == target)
        {
            res.push_back(path);
            return ;
        }

        for(int i=index; i<candidates.size() && sum+candidates[i]<=target; ++i)
        {
            /* 在同层递归中，对于重复元素，不再决策，直接跳过 */
            if(i>index && candidates[i] == candidates[i-1]) continue;

            path.push_back(candidates[i]);
            backtrace(candidates, i+1, sum+candidates[i]);
            path.pop_back();
        }
    }
};
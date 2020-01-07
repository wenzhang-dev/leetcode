class Solution {
    vector<vector<int>> res;
    int target;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        this->target = target;
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, vector<int>(), 0, 0);
        return res;
    }

    void backtrace(vector<int> &candidates, vector<int> subres, int sum, int index)
    {
        if(sum == target)
        {
            res.push_back(move(subres));
            return ;
        }
		
		/* 剪枝 */
		/* 每次决策时，需要下一个元素加入解时小于等于target */
		/* 每次遍历的初始值，总是从当前位置开始，因为选取的元素可重复 */
        for(int i=index; i<candidates.size() && sum+candidates[i]<=target; ++i)
        {
            subres.push_back(candidates[i]);
            backtrace(candidates, subres, sum+candidates[i], i); //从第i个位置开始遍历
            subres.pop_back();
        }
    }
};
class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res;
		res.reserve();
        backtrace(res, vector<int>(), 1, n, k);
        return res;
    }
    
    void backtrace(vector<vector<int>> &res, vector<int> subres, int start, int n, int k)
    {
        if(subres.size() == k)
        {
            res.push_back(subres);
            return ;
        }
        for(int i=start; i<=n; ++i)
        {
            if(find(subres.begin(), subres.end(), i) != subres.end()) continue;
            subres.push_back(i);
            backtrace(res, subres, i+1, n, k);
            subres.pop_back();
        }
    }
};

/* 优化 */
class Solution {
    int n, k;
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) 
    {
        this->n = n; this->k = k;
        backtrace(vector<int>(), 1);
        return res;
    }
    
    void backtrace(vector<int> subres, int start)
    {
        if(subres.size() == k)
        {
            res.push_back(subres);
            return ;
        }
        for(int i=start; i<=n; ++i)
        {
            subres.push_back(i);
            backtrace(subres, i+1);
            subres.pop_back();
        }
    }
};

/* 剪枝 */
class Solution {
    int n, k;
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) 
    {
        if(n<1 || k<1 || k>n) return res;

        this->n = n; this->k = k;
        backtrace(vector<int>(), 1);
        return res;
    }
    
    void backtrace(vector<int> subres, int start)
    {
        if(subres.size() == k)
        {
            res.push_back(subres);
            return ;
        }
		
		/* 保证start到n-(k-subres.size())+1有足够的元素容下k大小的解 */
        for(int i=start; i<=n-(k-subres.size())+1; ++i)
        {
            subres.push_back(i);
            backtrace(subres, i+1);
            subres.pop_back();
        }
    }
};
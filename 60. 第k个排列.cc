class Solution {
public:
    string getPermutation(int n, int k) 
    {
        vector<bool> visited(n);
        return helper(n, factorial(n-1), k, visited);
    }
    string helper(int n, int f, int k, vector<bool> &visited)
    {
        int offset = k % f;
        int groupIndex = k/f + (offset>0?1:0);
        int i=0;
        for(; i<visited.size() && groupIndex>0; ++i)
        {
            if(!visited[i]) groupIndex--;
        }
        visited[i-1] = true;
        if(n-1 > 0) return to_string(i) + helper(n-1, f/(n-1), offset==0?f:offset, visited);
        return to_string(i);
    }
    int factorial(int n)
    {
        int res=1;
        for(int i=n; i>1; --i) res *= i;
        return res;
    }
};
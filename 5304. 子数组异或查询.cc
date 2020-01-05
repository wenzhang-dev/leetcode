class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();
        vector<int> s(n+1);
        for (int i = 0; i < n; ++ i)
        {
            s[i+1] = s[i]^a[i];
        }
        vector<int> ret;
        for (auto e : queries)
        {
            int x = e[0]+1, y = e[1]+1;
            ret.push_back(s[y]^s[x-1]);
        }
        return ret;
    }
};
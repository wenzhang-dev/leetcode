/* 20ms */
struct cmp
{
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        return lhs.second > rhs.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> res;
        unordered_map<int, int> umap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        
        for(int num : nums) umap[num]++;
        for(const auto &elem : umap)
        {
            pq.push(std::move(elem));
            if(pq.size() > k) pq.pop(); /* 每次pop最小出现频率 */
        }

		while(!pq.empty())
        {
            const pair<int, int> &elem =  pq.top();
            res.push_back(elem.first);
            pq.pop();
        }

        return res;
    }
};

/* 优化: 12ms, 11.3MB */
struct cmp
{
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        return lhs.second < rhs.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> res;
        unordered_map<int, int> umap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        
        for(int num : nums) umap[num]++;
        for(const auto &elem : umap)
        {
            pq.push(std::move(elem));   /* 优先队列中从大至小排列 */
        }

        for(int i=0; i<k; ++i) 
        {
            const pair<int, int> &elem =  pq.top();
            res.push_back(elem.first);
            pq.pop();
        }

        return res;
    }
};
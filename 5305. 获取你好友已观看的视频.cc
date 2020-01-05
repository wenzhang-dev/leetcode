struct comp
{
    bool operator()(const pair<int, string> &lhs, const pair<int, string> &rhs)
    {
        if(lhs.first == rhs.first) return lhs.second > rhs.second;
        return lhs.first > rhs.first;
    }
};

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
    {
        //[0] -> [1, 2] -> [0, 3, 0, 3] -> [3]
        //[0] -> [1, 2]
        //[[1,2], [0, 2, 4, 5], [0, 3], [2], [1], [1]]
        //[0] -> [1, 2] -> [0, 2, 4, 5, 0, 3]
        unordered_set<int> accessId;
        queue<int> que;
        que.push(id); 
        
        for(int i=0; i<level; ++i)
        {
            int size = que.size();
            for(int j=0; j<size; ++j)
            {
                int index = que.front(); que.pop();
                accessId.insert(index);
                for(int item : friends[index])
                {
                    if(!accessId.count(item))
                    {
                        que.push(item);
                        accessId.insert(item);
                    }
                }
            }
        }
        
        map<string, int> memo;
        while(!que.empty())
        {
            int index = que.front(); que.pop();
            for(string &str : watchedVideos[index])
            {
                memo[str]++;
            }
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        //priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        for(auto &elem : memo)
        {
            pq.push(make_pair(elem.second, elem.first));
        }
     
        vector<string> res;
        while(!pq.empty())
        {
            const auto &elem = pq.top(); 
            res.push_back(elem.second);
            pq.pop();
        }
        return res;
    }
};
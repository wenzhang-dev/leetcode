/*  超出时间限制 */
struct comp
{
    bool operator()(const vector<string> &lhs, const vector<string> &rhs)
    {
        int size = lhs.size();
        for(int i=0; i<size; ++i)
        {
            if(lhs[i] != rhs[i]) return lhs[i] > rhs[i];
        }
        return false;
    }
};

class Solution {
    int level_;
    priority_queue<vector<string>, vector<vector<string>>, comp> pq_;
    multimap<string, string> mmap_;

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        level_ = tickets.size()+1;
        map<pair<string, string>, int> visited;

        for(auto &elem : tickets) 
        {
            mmap_.insert(make_pair(elem[0], elem[1]));
            visited[make_pair(elem[0], elem[1])]++;
        }
        
        vector<string> res{"JFK"};
        dfs(visited, 1, res);
        return pq_.top();
    }

    void dfs(map<pair<string, string>, int> &visit, int level, const vector<string> &path)
    {
        if(level >= level_) 
        {
            pq_.push(path);
            return ;
        }

        /* 相同的始发地 */
        auto sameStation = mmap_.equal_range(path.back());
        for(auto iter=sameStation.first; iter!=sameStation.second; ++iter)
        {
            if(visit[*iter] <= 0) continue;

            map<pair<string, string>, int> curVisit = visit;
            curVisit[*iter]--;
            vector<string> curPath = path;
            curPath.push_back(iter->second);

            dfs(curVisit, level+1, curPath);
        }
    }

};

/* 优化 */
class Solution {
    int level;
    vector<string> res;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        level = tickets.size() + 1;
        //map中value保证有序，所以dfs第一个结果即为答案
        map<string, map<string, int>> routePath, visited;
        vector<string> cur{"JFK"};
        for(auto &elem : tickets) routePath[elem[0]][elem[1]]++;
        
        dfs(routePath, visited, cur);
        return res;
    }

    void dfs(map<string, map<string, int>> &routePath, map<string, map<string, int>> &visited, vector<string> &path)
    {
        if(res.size() >= level) return ;
        else if(path.size() >= level)
        {
            res = path;
            return ;
        }

        auto &mp = routePath[path.back()];
        for(auto &iter : mp)
        {
            if(visited[path.back()][iter.first] >= routePath[path.back()][iter.first]) continue;
            visited[path.back()][iter.first]++;
            path.push_back(iter.first);
            dfs(routePath, visited, path);
            path.pop_back();
            visited[path.back()][iter.first]--;
            if(res.size() >= level) return ;
        }
    }
};
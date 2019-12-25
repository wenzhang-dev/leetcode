class Solution {
public:
    string simplifyPath(string path) 
    {
        string res;
        if(path.empty() || path[0] != '/') return res;

        deque<string> deq;
        int size = path.size();
        for(int i=0; i<size; ++i)
        {
            if(path[i] != '/') res.push_back(path[i]);
            else if(path[i] == '/')
            {
                if(res == "..")
                {
                    if(!deq.empty()) deq.pop_back();
                }
                else if(res == ".")
                {
                    //do nothing
                }
                else if(!res.empty()) deq.push_back(res);
                res.clear();
            }
        }

        if(res == "..") 
        {
            if(!deq.empty()) deq.pop_back();
            res.clear();
        }
        else if(res == ".") res.clear();

        string fullPath;
        while(!deq.empty())
        {
            fullPath += "/" + deq.front(); 
            deq.pop_front();
        }

        if(!res.empty()) fullPath += "/" + res;
        else if(fullPath.empty()) fullPath = "/";

        return fullPath;
    }
};

/* 字符流 */
class Solution {
public:
    string simplifyPath(string path) {
        stringstream is(path);
        vector<string> strs;
        string res = "", tmp = "";
        while(getline(is, tmp, '/')) {
            if(tmp == "" || tmp == ".")
                continue;
            else if(tmp == ".." && !strs.empty())
                strs.pop_back();
            else if(tmp != "..")
                strs.push_back(tmp);
        }
        for(string str:strs) 
            res +=  "/" + str;
        if(res.empty())
            return "/";
        return res;
    }
};

/* 优化: 4ms 9.8MB */
class Solution {
public:
    string simplifyPath(string path) 
    {
        string res;
        if(path.empty() || path[0] != '/') return res;  
        deque<string> sta;
        int size = path.size();
        for(int i=0; i<=size; ++i) /* 减少后续处理 */
        {
            if(i<size && path[i] != '/') res.push_back(path[i]);
            else
            {
                if(res == "..")
                {
                    if(!sta.empty()) sta.pop_back();
                }
                else if(!res.empty() && res != ".") sta.push_back(res);
                res.clear();
            }
        }

        string fullPath;
        while(!sta.empty())
        {
            fullPath += "/" + sta.front();
            sta.pop_front();
        }
        if(fullPath.empty()) return "/";

        return fullPath;
    }
};
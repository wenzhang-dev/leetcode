class Solution {
public:
    string decodeString(string s) 
    {
        string res;
        if(s.empty()) return res;

        stack<int> numSta;
        stack<string> resSta;
        int size = s.size();

        int num = 0;
        for(int i=0; i<size; ++i)
        {
            if(isalpha(s[i])) res.push_back(s[i]);
            else if(isdigit(s[i])) num = num*10 + s[i] - '0';
            else if(s[i] == '[')
            {
                numSta.push(num);
                num = 0;
                resSta.push(res);
                res.clear();
            } 
            else if(s[i] == ']')
            {
                int times = numSta.top();
                numSta.pop();
                for(int k=0; k<times; ++k) resSta.top() += res;
                res = resSta.top();
                resSta.pop();
            }
        }
        return res;
    }
};
class Solution {
public:
    int numDecodings(string s) 
    {
        //dp[i] : 字符串s前i个字符存在的编码数
        //s[i]=='0'
        //  s[i-1] == '0' || s[i-1] > 2 非法
        //  否则，dp[i] = dp[i-2]
        //s[i-1] == '0' 此时s[i]!='0',肯定i-1合法
        //  dp[i] = dp[i-1]
        //s[i-1] == '1'
        //  dp[i] = dp[i-1] + dp[i-2]
        //s[i-1] == '2' 
        //  s[i] <= 6
        //    dp[i] = dp[i-1] + dp[i-2]
        //  否则，dp[i] = dp[i-1]
        //否则，dp[i] = dp[i-1]
        if(s[0] == '0') return 0;
        vector<int> dp(s.size()+1);
        dp[0] = dp[1] = 1;
        for(int i=1; i<s.size(); ++i)
        {
            if(s[i] == '0')
            {
                if(s[i-1] == '0' || s[i-1] > '2') return 0; //非法
                else dp[i+1] = dp[i-1];
            }
            else if(s[i-1] == '0') dp[i+1] = dp[i];
            else if(s[i-1] == '1') dp[i+1] = dp[i] + dp[i-1];
            else if(s[i-1] == '2')
            {
                if(s[i] <= '6') dp[i+1] = dp[i] + dp[i-1];
                else dp[i+1] = dp[i];
            }
            else dp[i+1] = dp[i];
        }
        return dp[s.size()];
    }
};

/* 优化 */
class Solution {
public:
    int numDecodings(string s) 
    {
        if(s[0] == '0') return 0;
        int cur=1, prev=1, tmp;
        for(int i=1; i<s.size(); ++i)
        {
            tmp = cur;
            if(s[i] == '0')
            {
                if(s[i-1] == '0' || s[i-1] > '2') return 0; //非法
                else cur = prev;
            }
            else if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))
            {
                cur = cur + prev;  
            }
            prev = tmp;
        }
        return cur;
    }
};
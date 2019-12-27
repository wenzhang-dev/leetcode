class Solution {
public:
    int calculate(string s) 
    {
        stack<char> operatorSta;
        stack<int> numberSta;

        int size = s.size();
        for(int i=0; i<size; ++i)
        {
            if(s[i] == ' ') continue;
            else if(isdigit(s[i]))
            {
                string num;
                while(i<size && isdigit(s[i])) 
                {
                    num.push_back(s[i]);
                    ++i;
                }
                numberSta.push(stoi(num));
                --i;

                if(!operatorSta.empty() && (operatorSta.top() == '*' || operatorSta.top() == '/'))
                {
                    char op = operatorSta.top(); operatorSta.pop();
                    int opn = numberSta.top(); numberSta.pop();
                    if(op == '*') numberSta.top() *= opn;
                    else numberSta.top() /= opn;
                }
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                operatorSta.push(s[i]);
            }
        }

        int sum = 0;
        while(!operatorSta.empty())
        {
            char op = operatorSta.top(); operatorSta.pop();
            int opn = numberSta.top(); numberSta.pop();
            sum += op=='+'?opn:-opn;
        }
        return sum+numberSta.top();
    }
};
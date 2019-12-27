//40ms 11.3MB
class Solution {
public:
    int calculate(string s) 
    {
        stack<int> numberSta;
        stack<char> operatorSta;

        int size = s.size();
        for(int i=0; i<size; ++i)
        {
            if(s[i] == ' ') continue;
            else if(s[i] == '+' || s[i] == '-' || s[i] == '(')
            {
                operatorSta.push(s[i]);
            }
            else if(isdigit(s[i]))
            {
                int start = i;
                while(i<size && isdigit(s[i])) ++i;
                numberSta.push(stoi(s.substr(start, i-start)));
                --i;
            }
            else if(s[i] == ')')
            {
                int sum = 0;
                while(operatorSta.top() != '(')
                {
                    char op = operatorSta.top(); operatorSta.pop();
                    int opn = numberSta.top(); numberSta.pop();
                    sum += op=='+'?opn:-opn;
                }
                numberSta.top() += sum;
                operatorSta.pop();//()
                
            }
        }
        
        int sum = 0;
        while(!operatorSta.empty())
        {
            char op = operatorSta.top(); operatorSta.pop();
            int opn = numberSta.top(); numberSta.pop();
            sum += op=='+'?opn:-opn;
        }
        return sum + numberSta.top();
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        /* 两个栈: 数字和运算符 */
        stack<int> numberSta;

        for(const string &token : tokens)
        {
            if(token != "+" && token != "-" && token != "*" && token != "/")
            {
                numberSta.push(stoi(token));
                continue;
            }

            int op1 = numberSta.top(); numberSta.pop();
            int op2 = numberSta.top(); numberSta.pop();
            if(token[0] == '+') numberSta.push(op2+op1);
            else if(token[0] == '-') numberSta.push(op2-op1);
            else if(token[0] == '*') numberSta.push(op2*op1);
            else numberSta.push(op2/op1);
        }

        return numberSta.top();
    }
};

/* 优化 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        /* 两个栈: 数字和运算符 */
        stack<int> numberSta;
        for(const string &token : tokens)
        {
            if((token[0] >= '0' && token[0] <= '9') || (token[0] == '-' && token.size() > 1))
            {
                numberSta.push(stoi(token));
                continue;
            }

            int op1 = numberSta.top(); numberSta.pop();
            int op2 = numberSta.top(); numberSta.pop();
            if(token[0] == '+') numberSta.push(op2+op1);
            else if(token[0] == '-') numberSta.push(op2-op1);
            else if(token[0] == '*') numberSta.push(op2*op1);
            else numberSta.push(op2/op1);
        }

        return numberSta.top();
    }
};
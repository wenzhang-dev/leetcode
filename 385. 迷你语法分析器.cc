/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) 
    {
        if(s[0] != '[') return NestedInteger(stoi(s));

        stack<NestedInteger *> sta;
        int size = s.size();
        string num;
        for(int i=0; i<size; ++i)
        {
            if(isdigit(s[i]) || s[i] == '-') num.push_back(s[i]);
            else if(s[i] == '[')
            {
                NestedInteger *ni = new NestedInteger();
                sta.push(ni);
            }
            else if(s[i] == ',')
            {
                if(!num.empty())
                {
                    sta.top()->add(NestedInteger(stoi(num)));
                    num.clear();
                }
            }
            else if(s[i] == ']')
            {
                if(!num.empty())
                {
                    sta.top()->add(NestedInteger(stoi(num)));
                    num.clear();
                }
                NestedInteger *ni = sta.top(); sta.pop();
                if(sta.empty()) return *ni;
                else sta.top()->add(*ni);
            }
        }
        return NestedInteger();
    }
};

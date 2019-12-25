class MyStack {
    queue<int> que;
    queue<int> helper;

public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x;
        while(!que.empty())
        {
            x = que.front(); 
            que.pop();
            if(que.empty()) break;
            helper.push(x);
        }
        std::swap(que, helper);
        return x;
    }
    
    /** Get the top element. */
    int top() {
        int x;
        while(!que.empty())
        {
            x = que.front(); 
            que.pop();
            helper.push(x);
        }
        std::swap(que, helper);
        return x;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
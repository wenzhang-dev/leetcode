class MyQueue {
    stack<int> inStack;       /* 负责装入元素 */
    stack<int> outStack;      /* 负责推出元素 */

public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int elem = peek();
        outStack.pop();
        return elem;
    }
    
    /** Get the front element. */
    int peek() {
        if(outStack.empty())
        {
            while(!inStack.empty())
            {
                int x = inStack.top();
                inStack.pop();
                outStack.push(x);
            }
        }
        int elem = outStack.top();
        return elem;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
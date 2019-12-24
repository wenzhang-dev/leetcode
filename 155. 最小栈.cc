class MinStack {
    stack<int> sta_;
    multiset<int> uset_;

public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        sta_.push(x);
        uset_.insert(x);
    }
    
    void pop() {
        int x = sta_.top();
        sta_.pop();
        auto iter = uset_.find(x);
        uset_.erase(iter);
    }
    
    int top() {
        return sta_.top();
    }
    
    int getMin() {
        return *uset_.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 
/* 双栈: 36ms */
class MinStack {
    stack<int> elemSta;
    stack<int> minSta;

public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        elemSta.push(x);
        if(minSta.empty() || minSta.top() >= x) minSta.push(x);
    }
    
    void pop() {
        //assert(!elemSta.empty());
        int x = elemSta.top();
        if(!minSta.empty() && minSta.top() == x) minSta.pop();
        elemSta.pop();
    }
    
    int top() {
        //assert(!elemSta.empty());
        return elemSta.top();
    }
    
    int getMin() {
        //assert(!minSta.empty());
        return minSta.top();
    }
};
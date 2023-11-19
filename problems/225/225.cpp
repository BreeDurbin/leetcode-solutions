class MyStack {
public:
    queue<int> q0, q1;
    int topp;
    MyStack() {
        
    }
    
    void push(int x) {
        q0.push(x);
        topp = x;
    }
    
    int pop() {
        while(q0.size() > 1){
            topp = q0.front();
            q0.pop();
            q1.push(topp);
        }

        int ret = q0.front();
        q0.pop();
        swap(q0,q1);
        return ret;
    }
    
    int top() {
        return topp;
    }
    
    bool empty() {
        return q0.empty();
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
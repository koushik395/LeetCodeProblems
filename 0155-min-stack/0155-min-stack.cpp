class MinStack {
public:
    vector<pair<int, int>> store;
    MinStack() {
        
    }
    
    void push(int val) {
        if(store.empty())
        {
            store.push_back({val, val});
        }
        else
        {
            store.push_back({val, min(store.back().second, val)});
        }
    }
    
    void pop() {
        store.pop_back();
    }
    
    int top() {
        return store.empty() ? -1 : store.back().first;
    }
    
    int getMin() {
        return store.empty() ? -1 : store.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
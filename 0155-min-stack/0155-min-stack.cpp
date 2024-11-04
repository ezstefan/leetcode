class MinStack {
    stack<pair<int,int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val,val});
        }
        else{
            st.push({val, min(val,st.top().second)});
        }

        
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        int n = st.top().first;
        return n;
        
    }
    
    int getMin() {
        int min = st.top().second;
        return min;
        
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
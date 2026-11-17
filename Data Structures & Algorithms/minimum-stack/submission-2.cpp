class MinStack {
public:
    stack<int> st;
    stack<int> minVal;
    MinStack() {
        
    }
    
    void push(int val) {
       st.push(val);
       val = min(val, minVal.empty() ? val : minVal.top());
       minVal.push(val);
    }
    
    void pop() {
        minVal.pop();
        st.pop();
    }
    
    int top() {
    return st.top();
    }
    
    int getMin() {
        int min = minVal.top();
        return min;
    }
};

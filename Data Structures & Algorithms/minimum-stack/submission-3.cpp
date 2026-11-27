class MinStack {
public:
    stack<pair<int, int>> st;
    int minSoFar = INT_MAX;
    MinStack() {
    }
    
    void push(int val) {
        st.push(make_pair(val, minSoFar));
        minSoFar = min(minSoFar, val);
    }
    
    void pop() {
        minSoFar = st.top().second;
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return minSoFar;
    }
};

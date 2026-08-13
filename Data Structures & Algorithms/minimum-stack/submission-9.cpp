class MinStack {
public:
    stack<long long> st;
    long long minVal = LLONG_MAX;

    MinStack() {
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minVal = val;
        }
        else {
            if (val < minVal) {
                st.push(2LL * val - minVal);
                minVal = val;
            }
            else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if (st.top() < minVal) {
            minVal = 2 * minVal - st.top();
        }

        st.pop();
    }
    
    int top() {
        if (st.top() < minVal) {
            return minVal;
        }
        else {
            return st.top();
        }
    }
    
    int getMin() {
        return minVal;
    }
};
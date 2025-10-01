class MinStack {
public:
    stack<pair<int,int>> st;
    int minval;

    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            minval = val;
        } else {
            minval = min(val, st.top().second);
        }
        st.push({val, minval});
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftmin(n), rightmin(n), leftmax(n), rightmax(n);
        stack<int> st;

        // --- left min ---
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            leftmin[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop(); // clear stack

        // --- right min ---
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            rightmin[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // --- left max ---
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            leftmax[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // --- right max ---
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            rightmax[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long totalMax = (long long)arr[i] * leftmax[i] * rightmax[i];
            long long totalMin = (long long)arr[i] * leftmin[i] * rightmin[i];
            ans += (totalMax - totalMin);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;  

        for(int i = 2 * n - 1; i >= 0; i--) {
            int currIndex = i % n;

            while (!st.empty() && nums[st.top()] <= nums[currIndex]) {
                st.pop();
            }

            if (i < n) {
                nge[currIndex] = st.empty() ? -1 : nums[st.top()];
            }

            st.push(currIndex);
        }

        return nge;
    }
};

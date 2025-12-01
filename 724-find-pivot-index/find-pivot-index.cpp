class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            pre[i] = pre[i-1] + nums[i];
        }
        for(int i = 0; i < n; i++)
        {
            int leftsum = (i == 0 ? 0 : pre[i-1]);
            int rightsum = pre[n-1] - pre[i];
            if(leftsum == rightsum)return i;
        }
        return -1;
    }
};
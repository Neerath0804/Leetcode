class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, maxi_sum = INT_MIN;
        for(int i = 0; i < n;i++)
        {
            sum += nums[i];
            maxi_sum = max(sum, maxi_sum);
            if(sum < 0)
            {
                sum = 0;
            }
            
        }
       return maxi_sum;
    }
};
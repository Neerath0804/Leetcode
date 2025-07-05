class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int i = 0, j = 0, cnt = 0, prefix = 0, n = nums.size();
        unordered_map<int, int> mpp;

        while (j < n) {
            mpp[nums[j]]++;

            if (mpp.size() > k) {
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
                prefix = 0; 
            }

            while (mpp.size() == k && mpp[nums[i]] > 1) {
                mpp[nums[i]]--;
                i++;
                prefix++;
            }

            if (mpp.size() == k) {
                cnt += prefix + 1;
            }

            j++;
        }

        return cnt;
    }
};

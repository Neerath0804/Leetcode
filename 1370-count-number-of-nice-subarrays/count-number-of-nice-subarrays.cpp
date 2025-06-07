class Solution {
public:
    int countAtMost(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, cnt = 0, odd = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] % 2 != 0) odd++;

            while (odd > k) {
                if (nums[left] % 2 != 0) odd--;
                left++;
            }

            cnt += right - left + 1;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};

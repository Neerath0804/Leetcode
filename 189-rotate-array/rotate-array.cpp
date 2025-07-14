class Solution {
public:
void reverse_array(vector<int>& nums, int st, int end)
{
     while(st < end)
        {
            swap(nums[st],nums[end]);
            st++;
            end--;
        }
}
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
      reverse_array(nums,0,n-1);
      reverse_array(nums,0,k-1);
      reverse_array(nums,k,n-1);
    }
};
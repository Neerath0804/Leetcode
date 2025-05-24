class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged(nums1.size() + nums2.size());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),merged.begin());
        int n = merged.size();
        
        if(n%2 == 0)
        {
             return (merged[n/2] + merged[n/2 - 1]) / 2.0 ;
        }
        else
       {
        return (merged[n/2]);
       }
    }
};
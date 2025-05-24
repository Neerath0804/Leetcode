class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       
    int n = nums.size();
    vector<vector<int>>ans= {{}};
    for(auto num : nums)
    {
        int size = ans.size();
        for(int i = 0;i<size;i++)
        {
            vector<int>sub = ans[i];
            sub.push_back(num);
            ans.push_back(sub);
        }
    }
    return ans;
        
    }
};
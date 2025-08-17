class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mpp;
        for(auto & str : strs)
        {
            string s = str;
            sort(s.begin(),s.end());
            mpp[s].push_back(str);
        }
      for(auto & val : mpp)
      {
        ans.push_back(val.second);
      }
      return ans;
    }
};
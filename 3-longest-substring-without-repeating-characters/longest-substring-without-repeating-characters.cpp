class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maxlen = 0;
        unordered_map<char,int>mpp;
        int left = 0;
        for(int right = 0; right < n; right++)
        {
            if(mpp.find(s[right]) != mpp.end())
            {
               left = max(left,mpp[s[right]]+1);
            }
             mpp[s[right]] = right;
            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;

    }
};
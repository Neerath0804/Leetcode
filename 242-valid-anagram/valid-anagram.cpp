class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mpp1,mpp2;
        int n = s.size(), m = t.size();
        if(n != m)return false;
        for(int i = 0; i < n; i++)
        {
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }
        return mpp1 == mpp2;
    }
};
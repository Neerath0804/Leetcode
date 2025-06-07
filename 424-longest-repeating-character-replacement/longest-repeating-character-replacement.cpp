class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0; int right = 0;
        int maxlen = 0, maxfreq = 0;
        unordered_map<int, int> mpp;
        while(right < n)
        {
            mpp[s[right] - 'A']++;
            maxfreq = max(maxfreq,mpp[s[right]-'A']);

            if((right-left+1) - maxfreq   > k)
            {
                mpp[s[left]-'A']--;
                maxfreq = 0;
                left++;
            }
            if((right-left+1) - maxfreq  <= k)
            {
                maxlen = max(maxlen, right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};
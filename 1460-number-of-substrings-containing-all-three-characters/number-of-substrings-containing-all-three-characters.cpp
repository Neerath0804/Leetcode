class Solution {
public:
    int numberOfSubstrings(string s) {
         unordered_map<char,int> mpp;
    int n = s.size();
    int i = 0, j = 0, cnt = 0, k = 3;

    while (j < n)
    {
        mpp[s[j]]++;

        while (mpp.size() == k)
        {
            cnt += n - j;
            mpp[s[i]]--;
            if (mpp[s[i]] == 0)
            {
                mpp.erase(s[i]);
            }
            i++;
        }

        j++;
    }
    return cnt;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> mpp;
        for (char c : t) mpp[c]++;

        int count = t.size();  // total characters to match
        int i = 0, j = 0, min_len = INT_MAX, start = 0;

        while (j < s.size()) {
            if (mpp[s[j]] > 0) count--;
            mpp[s[j]]--;
            j++;

            while (count == 0) {  // valid window found
                if (j - i < min_len) {
                    min_len = j - i;
                    start = i;
                }

                mpp[s[i]]++;
                if (mpp[s[i]] > 0) count++;  // lost a needed char
                i++;
            }
        }

        return (min_len == INT_MAX) ? "" : s.substr(start, min_len);
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int st = 0;
        int end = n - 1;
        while(end >= st)
        {
            swap(s[end--],s[st++]);
        }
    }
};
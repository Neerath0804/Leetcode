class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        string ans = "";
        stack<char>st;
        for(char c : num)
        {
            while(!st.empty() && k > 0 && st.top() > c)
            {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(!st.empty() && k > 0)
        {
            st.pop();
            k--;
        }
        while(!st.empty())
        {
            ans += st.top();;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        while(i < ans.length() && ans[i] == '0') i++;
        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};
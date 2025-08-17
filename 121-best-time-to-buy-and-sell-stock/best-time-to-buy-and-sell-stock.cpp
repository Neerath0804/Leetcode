class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = INT_MAX;  // track lowest price so far
        int profit = 0;      // max profit

        for (int i = 0; i < n; i++) {
            mini = min(mini, prices[i]);              // update minimum
            profit = max(profit, prices[i] - mini);   // check profit if sold today
        }
        return profit;
    }
};

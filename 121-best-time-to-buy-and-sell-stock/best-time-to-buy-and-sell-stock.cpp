class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = INT_MAX, profit = 0;
        for(int i = 0; i < n ; i++)
        {
            if(prices[i]<mini)mini = prices[i];
            int currprofit = prices[i] - mini;
            profit  = max(profit,currprofit);
        }
        return profit;
    }
};
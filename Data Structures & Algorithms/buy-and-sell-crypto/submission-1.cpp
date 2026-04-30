class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buy = INT_MAX, sell = INT_MIN;
        int n = prices.size();
        if(n < 2)
            return maxProfit;
        for(int i = 0; i < n; i++){
            if(prices[i] <= buy){
                buy = prices[i];
                sell = 0;
            }
            else if(prices[i] > sell)
                sell = prices[i];
            maxProfit = max(maxProfit, sell-buy);
        }
        return maxProfit;
    }
};

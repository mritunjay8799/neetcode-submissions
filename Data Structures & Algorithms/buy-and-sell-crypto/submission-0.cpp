class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        if(n < 2)
            return maxProfit;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j<n; j++){
                maxProfit = max(maxProfit, prices[j]-prices[i]);
            }
        }
        return maxProfit;
    }
};

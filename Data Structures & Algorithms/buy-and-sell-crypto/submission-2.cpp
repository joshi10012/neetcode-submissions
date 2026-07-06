class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int profit = 0, minValue = prices[0];
        for(auto price:prices){
            profit = max(profit, price-minValue);
            minValue = min(minValue, price);
        }
        return profit;
    }
};

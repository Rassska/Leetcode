class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        
        std::vector<int> sell(prices.size(), 0), buy(prices.size(), -prices[0] - fee);
        
        for (std::size_t i = 1; i < prices.size(); i++) {
            buy[i] = std::max(buy[i - 1], sell[i - 1] - prices[i] - fee);
            sell[i] = std::max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return sell[prices.size() - 1];
    }
};
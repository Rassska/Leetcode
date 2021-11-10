class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int leftMin = std::numeric_limits<int>::max();
        
        for (std::size_t i = 0; i < prices.size(); i++) {
            leftMin = std::min(leftMin, prices[i]);
            profit = std::max(profit, prices[i] - leftMin);
        }
        
        return profit;
    }
};
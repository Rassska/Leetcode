class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int no_hold = 0;
        int hold = INT_MIN;
        
        for (std::size_t i = 0; i < prices.size(); i++) {
            int no_hold_old = no_hold;
            no_hold = std::max(no_hold, hold + prices[i]);
            hold = std::max(hold, no_hold_old - prices[i]);
        }
        
        return no_hold;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        // 1) Claryfying the problem
            // 1.1) 1 <= prices.size() <= 10^5
            // 1.2) 0 <= prices[i] <= 10^4
            // 1.3) returning max profit
        
        
        // 2) Initial approaches
            // 2.1) brute force
        
        
        // 3) Solution
        
        int maxProfit = 0;
        int currMin = std::numeric_limits<int>::max();
        std::vector<int> dp(prices.size());
        
        for (std::size_t i = 0; i < prices.size(); i++) {
            currMin = min (currMin, prices[i]);
            dp[i] = prices[i] - currMin; 
        }
        
        
        return *max_element(dp.begin(), dp.end());
        
        // 4) Debugging
            // 4.1) [7, 1, 5, 3, 6, 4] 
        
        // 5) Analyzing
            // 5.1) Time complexity - O((prices.size())^2)
            // 5.2) Space complexity - O(1)
        
        
        
        
    }
};
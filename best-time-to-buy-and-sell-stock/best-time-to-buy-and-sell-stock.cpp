class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
    // minSoFar - min{prices[0]...prices[i]}
        
    // dp[i] = prices[i] - minSoFar
        
    
        int minSoFar = prices[0];
        int ans = 0;
        for (std::size_t i = 1; i < prices.size(); i++) {
            ans = std::max(ans, prices[i] - minSoFar);
            minSoFar = std::min(minSoFar, prices[i]);
        }
    
        return ans;
    }
};
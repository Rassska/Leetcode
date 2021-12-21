class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        std::vector<int> dp(cost.size() + 5);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for (std::size_t i = 2; i < cost.size(); i++) {
            dp[i] = std::min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
        }
        dp[cost.size()] = std::min(dp[cost.size() - 1], dp[cost.size() - 2]);
        return dp[cost.size()];
        
        
    }
};
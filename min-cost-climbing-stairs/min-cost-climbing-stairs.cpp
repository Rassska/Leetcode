class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        
        
        /*
        dp[0] = 0;
        dp[1] = 10;
        dp[2] = 15;
        dp[3] = 30;
        dp[4] = 15;
        
        
        */ 
        std::vector<int> dp(cost.size() + 2);
        dp[0] = 0;
        dp[1] = cost[0];
        for (std::size_t i = 2; i <= cost.size() + 1; i++) {
            if (i - 1 < cost.size()) {
                dp[i] = std::min((dp[i - 2] + cost[i - 1]), (dp[i - 1] + cost[i - 1]));
            } else {
                dp[i] = std::min(dp[i - 2], dp[i - 1]);
            }
            
        }
        return dp[cost.size() + 1];
        
        
    }
};
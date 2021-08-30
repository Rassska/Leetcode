class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        
        // 1) Claryfying the given problem
            // 1.1) 1 <= coins.size() <= 12
            // 1.2) 1 <= coins[i] <= 2^31 - 1
            // 1.3) 0 <= amount <= 10^4
            // 1.4) return the min wat to add up amount with coins, unless return -1
        
        // 2) Intial approaches
        
        // 3) Solution
        
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (std::size_t i = 0; i <= amount; i++) {
            for (std::size_t j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        
        if (dp[amount] <= amount) {
            return dp[amount];
        } else {
            return -1;
        }
           
        
        
    }
};
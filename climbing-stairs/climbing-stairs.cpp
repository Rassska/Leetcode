class Solution {
public:
    int climbStairs(int n) {
        
        if (n == 1) {
            return 1;
        }
        std::vector<int> dp(n + 1);
        
        dp[1] = 1;
        dp[2] = 2;
        
        for (std::size_t i = 3; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        
        return dp[n];
    }
};
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        std::vector<std::vector<short>> dp(text1.size() + 1, std::vector<short> (text2.size() + 1));
        
        for (std::size_t i = 1; i <= text1.size(); i++) {
            for (std::size_t j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        
        return dp[text1.size()][text2.size()];
        
        
        
    }
};
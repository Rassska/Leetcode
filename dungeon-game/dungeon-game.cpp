class Solution {
public:
    
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        std::vector<std::vector<int>> dp(dungeon.size() + 1, std::vector<int>(dungeon[0].size() + 1, std::numeric_limits<int>::max()));
        
        dp[dungeon.size() - 1][dungeon[0].size()] = 1;
        dp[dungeon.size()][dungeon[0].size() - 1] = 1;
        
        for (int i = dungeon.size() - 1; i > -1; i--) {
            for (int j = dungeon[0].size() - 1; j > -1; j--) {
               dp[i][j] = std::max(1, std::min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
        
    }
private:
    
};
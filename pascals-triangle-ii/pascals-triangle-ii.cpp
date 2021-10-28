class Solution {
public:
    

    vector<int> getRow(int rowIndex) {
        dp.resize(rowIndex + 1, {});
        if (rowIndex == 0) {
            return {1};
        } else if (rowIndex == 1) {
            return {1, 1};
        }
        dp[0] = {1};
        dp[1] = {1, 1};
        
        for (std::size_t i = 2; i <= rowIndex; i++) {
            std::vector<int> currLayer;
            
            for (std::size_t j = 0; j <= dp[i - 1].size(); j++) {
                if (j == 0 || j == dp[i - 1].size()) {
                    currLayer.push_back(1);
                } else {
                    currLayer.push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
                }
            }
            dp[i] = currLayer;
        }
        return dp[rowIndex];
        
        
    }
private:
    std::vector<std::vector<int>> dp;
};
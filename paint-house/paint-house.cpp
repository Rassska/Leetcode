class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        
        
        std::vector<int> dp(costs.size(), INT_MAX);
        std::vector<std::vector<int>> dpHelper = costs;
        
        dp[0] = *(std::min_element(costs[0].begin(), costs[0].end()));
        
        for (std::size_t i = 1; i < costs.size(); i++) {
            std::vector<int> rightMin(dpHelper[i - 1].size(), INT_MAX), leftMin(dpHelper[i - 1].size(), INT_MAX);
            
            rightMin[0] = dpHelper[i - 1][dpHelper[i].size() - 1];
            leftMin[0] = dpHelper[i - 1][0];
            for (std::size_t j = 1; j < costs[i - 1].size(); j++) {
                leftMin[j] = std::min(leftMin[j - 1], dpHelper[i - 1][j]);
            }
            uint32_t suffIdx = 1;
            for (int j = costs[i].size() - 2; j >= 0; j--) {
                rightMin[suffIdx++] = std::min(rightMin[suffIdx - 1], dpHelper[i - 1][j]);
            }
            
            for (std::size_t j = 0; j < costs[i].size(); j++) {
                if (j > 0 && j + 1 < costs[i].size()) {
                    dpHelper[i][j] = costs[i][j] + std::min(leftMin[j - 1], rightMin[costs[i - 1].size() - j - 2]);
                } else if (j > 0) {
                    dpHelper[i][j] = costs[i][j] + leftMin[j - 1];
                } else if (j + 1 < costs[i].size()) {
                    dpHelper[i][j] = costs[i][j] + rightMin[costs[i - 1].size() - j - 2];
                }
            }
            dp[i] = *(std::min_element(dpHelper[i].begin(), dpHelper[i].end()));
            
            
        }
        
        return dp[costs.size() - 1];
    }
};
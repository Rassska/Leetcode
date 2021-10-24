class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        
        
        std::vector<std::vector<long long>> dp(points.size(), std::vector<long long>(points[0].size(), 0));
        
        for (std::size_t i = 0; i < points[0].size(); i++) {
            dp[0][i] = points[0][i];
        }
        long long ans = 0;
        for (std::size_t i = 1; i < points.size(); i++) {
            
            std::vector<long long> l2r(points[i].size()), r2l(points[i].size());
            l2r[0] = dp[i - 1][0];
            r2l[r2l.size() - 1] = dp[i - 1][dp[i - 1].size() - 1];
            
            for (std::size_t j = 1; j < points[i].size(); j++) {
                l2r[j] = std::max(l2r[j - 1] - 1, dp[i - 1][j]);
                r2l[points[i].size() - 1 - j] = std::max(r2l[points[i].size() - j] - 1, dp[i - 1][points[i].size() - 1 - j]);
            }
            
            for (std::size_t j = 0; j < points[i].size(); j++) {
                dp[i][j] = points[i][j] + std::max(l2r[j], r2l[j]);
            }
        }
        
        for (std::size_t i = 0; i < dp.size(); i++) {
            ans = std::max(ans, *(std::max_element(dp[i].begin(), dp[i].end())));
        }
        return ans;
        
        
        
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        
        std::vector<int> dp(height.size());
        int currMaxHeight = std::numeric_limits<int>::min();
        int ans = 0;
        
        for (int i = 0; i < height.size(); i++) {
            currMaxHeight = std::max(currMaxHeight, height[i]);
            dp[i] = currMaxHeight - height[i];
        }
        
        currMaxHeight = -1;
        
        for (int i = height.size() - 1; i > -1; i--) {
            currMaxHeight = std::max(currMaxHeight, height[i]);
            ans += std::min(currMaxHeight - height[i], dp[i]);
        }
        return ans;
        
    }
};
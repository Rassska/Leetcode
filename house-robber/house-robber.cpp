class Solution {
public:
    int rob(vector<int>& nums) {
        
        
        std::vector<uint16_t> dp(nums.size() + 1, 0);
        uint32_t ans = 0, maxIdx = 0;
        
        dp[0] = nums[0];
        if (nums.size() > 1) {
            dp[1] = nums[1];
        }
        
        for (std::size_t i = 2; i < nums.size(); i++) {
            if (dp[i - 2] > dp[maxIdx]) {
                maxIdx = i - 2;
            }
            
            dp[i] = dp[maxIdx] + nums[i];
           
        }
        
        
        return *(std::max_element(dp.begin(), dp.end()));
        
        
    }
};
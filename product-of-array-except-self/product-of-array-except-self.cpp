class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        std::vector<int> ans(nums.size());
        
        std::vector<int> preff(nums.size() + 1), suff(nums.size() + 1);
        preff[0] = suff[0] = 1;
        
        for (std::size_t i = 0; i < nums.size() - 1; i++) {
            preff[i + 1] = preff[i] * nums[i];
        }
        
        uint32_t suffIdx = 1;
        
        for (int i = nums.size() - 1; i >= 1; i--) {
            suff[suffIdx++] = suff[suffIdx - 1] * nums[i];
        }
        
        for (std::size_t i = 0; i < nums.size(); i++) {
            ans[i] = preff[i] * suff[nums.size() - 1 - i];
        }
        
        return ans;
    }
};
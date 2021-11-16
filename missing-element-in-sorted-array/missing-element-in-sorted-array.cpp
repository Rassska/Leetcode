class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        
        
        for (std::size_t i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] > k) {
                return nums[i - 1] + k;
            } else if (nums[i] - nums[i - 1] != 1 && nums[i] - nums[i - 1] <= k) {
                k -= (nums[i] - nums[i - 1] - 1);
            }
        }
        return nums[nums.size() - 1] + k;
        
    }
};
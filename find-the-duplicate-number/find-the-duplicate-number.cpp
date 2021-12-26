class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        
        std::sort(nums.begin(), nums.end());
        
        for (std::size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;
        
        
    }
};
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        
        for (std::size_t i = 1; i < nums.size(); i++) {
            nums[i] = nums[i - 1] + nums[i];
        }
        
        return nums;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        
        std::vector<int> ans;
        for (std::size_t i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (std::size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
        
        
    }
};
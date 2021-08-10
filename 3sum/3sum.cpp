class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        
        for (std::size_t i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    
                    std::vector<int> tempAns = {-target, nums[left], nums[right]};
                    ans.push_back(tempAns);
                    
                    while (left < right && nums[left] == tempAns[1]) left++;
                    while (left < right && nums[right] == tempAns[2]) right--;
                }
            }
            
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return ans;
        
    }
};
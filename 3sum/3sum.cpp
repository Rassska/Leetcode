class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        std::vector<std::vector<int>> ans;
        if (nums.size() < 3) {
            return ans;
        }
        
        std::sort(nums.begin(), nums.end());
        
        // nums = {-4, -1, -1, 0, 1, 2}
        for (std::size_t i = 0; i < nums.size() - 1; i++) {
            
            int first = nums[i];
            int target = -1 * first;
            int left = i + 1;
            int right = nums.size() - 1;
            
            
            while (left < right) {
                
                if (nums[left] + nums[right] < target) {
                    left++;
                } else if (nums[left] + nums[right] > target) {
                    right--;
                } else {
                    std::vector<int> currTriplet = {first, nums[left], nums[right]};
                    ans.push_back(currTriplet);
                    
                    while (left < right && nums[left] == currTriplet[1]) left++;
                    while (left < right && nums[right] == currTriplet[2]) right--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                i++;
            }
            
        }
        
        return ans;
        
    }
};
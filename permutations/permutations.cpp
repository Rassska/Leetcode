class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        // 1) Claryfying the problem
            // 1.1) 0 <= nums.size() <= 6
            // 1.2) -10 <= nums[i] <= 10
            // 1.3) all integers of nums are unique
            // 1.4) return all permutations of nums
            // 1.5) n! - amount of permutations
        
        // 2) Initial approaches 
            // 2.0) recursion method
            // 2.1) 123 -> 123, 123 -> 213, 123 -> 321
            // 2.2) 123 -> 123, 123 -> 132, 123 -> 213, 213 -> 231, 123 -> 321, 321 -> 312
        
        // 3) Solution
        
        std::vector<std::vector<int>> result;
        permuteRecursive(nums, 0, result);
        return result;
            
        
    }
    
    void permuteRecursive(std::vector<int>& nums, int begin, std::vector<std::vector<int>>& result) {
        
        if (begin == nums.size()) {
            result.push_back(nums);
            return;
        } else {
            
            for (std::size_t i = begin; i < nums.size(); i++) {
                std::swap(nums[begin], nums[i]);
                permuteRecursive(nums, begin + 1, result);
                std::swap(nums[begin], nums[i]);
            }
        }
    }
    
    
};
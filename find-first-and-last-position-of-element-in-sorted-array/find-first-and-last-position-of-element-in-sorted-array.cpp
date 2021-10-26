class Solution {
public:
    
    
    int findBound (std::vector<int>& nums, int target, bool isFirst) {
        
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (nums[mid] == target) {
                if (isFirst) {
                    if (mid == left || nums[mid - 1] != target) {
                        return mid;
                    } 
                    
                    right = mid - 1;
                    
                } else {
                    if (mid == right || nums[mid + 1] != target) {
                        return mid;
                    }
                    left = mid + 1;
                } 
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            
        }
        return -1;
        
        
        
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        std::vector<int> ans = {-1, -1};
        if (!nums.size()) {
            return ans;
        } else {
            ans[0] = findBound(nums, target, true);
            ans[1] = findBound(nums, target, false);
        }
        
        return ans;
        
    }
};
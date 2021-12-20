class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                right = mid;
            } else if (mid + 1 < nums.size() && nums[mid + 1] > nums[mid]) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        
        return left;
        
    }
};
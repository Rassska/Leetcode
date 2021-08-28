class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        
        // 1) Claryfying the problem
            // 1.1) -10^9 <= nums[i] <= 10^9 , for target the same constraints
            // 1.2) 0 <= nums.size() <= 10^5
            // 1.3) return first and last entry indices of target or <-1, -1> if target doesn't exist
        
        // 2) Initial approaches
            // 2.1) brute force => finding the first and the last entry points. O(n) - time compl, O(1) - space
            // 2.2) binary search the first entry index of target and the last one separately. O(log n) - time compl, O(1) - space
        
        // 3) Solution
        
        int left = 0, right = nums.size(), first = -1, last = -1;
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        first = left;
        left = 0;
        right = nums.size();
        
        while (left < right) {
            int mid = (right + left) / 2;
            
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        last = left;
        
        return last == first ? std::vector<int>{-1, -1} : std::vector<int>{first, last - 1};
        
    }
    
};
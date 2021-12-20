class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            
            int mid = left + (right - left) / 2;
            if (right - left == 1 && nums[left] + k < nums[right]) {
                return nums[left] + k;
            } else if (right - left == 1) {
                k -= nums[right] - nums[left] - 1;
                break;
            }
            
            if (((nums[mid] - nums[left]) - (mid - left)) >= k) {
                right = mid;   
            } else {
                k -= ((nums[mid] - nums[left]) - (mid - left));
                left = mid;
            }
        }
        return nums.back() + k;
        
        
    }
};



// TC: O(g(n)), where n - nums.size()
// SC: O(1)


// nums = [4,7,9,10], k = 4
// mid = 1, left = 0, right = 3; 
// mid - left = 1
// nums[mid] - nums[left] - (mid - left) < k
//       


// TC: O(g(log(n))), where n - nums.size()
// SC: O(f(1))
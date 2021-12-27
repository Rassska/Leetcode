class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int left = 0;
        int ans = 0;
        int tempK = k;
        
        for (int i = 0; i < nums.size(); i++) {
            
            while (nums[i] == 0 && tempK == 0) {
                if (nums[left] == 0) {
                    tempK++;
                }
                left++;
            }
            if (nums[i] == 0) {
                tempK--;
            }
            
            ans = std::max(ans, i - left + 1);
            
        }
        
        
        return ans;
    }
};
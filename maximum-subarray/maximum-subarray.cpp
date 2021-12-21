class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int largestSum = INT_MIN;
        int localSum = 0;
        for (std::size_t i = 0; i < nums.size(); i++) {
            localSum += nums[i];
            largestSum = std::max(largestSum, localSum);
            if (localSum < 0) {
                localSum = 0;
            } 
            
        }
        return largestSum;
        
    }
};
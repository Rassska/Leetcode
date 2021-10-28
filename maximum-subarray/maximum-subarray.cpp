class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currSum = 0;
        int maxSum = std::numeric_limits<int>::min();
        
        for (auto num : nums) {
            currSum += num;
            maxSum = std::max(maxSum, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
        
    }
};
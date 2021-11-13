class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        
        std::vector<int> leftPrefMin(nums.size() + 1), rightSuffMax(nums.size() + 1);
        leftPrefMin[0] = std::numeric_limits<int>::max();
        rightSuffMax[0] = std::numeric_limits<int>::min();
        
        for (std::size_t i = 0; i < nums.size(); i++) {
            leftPrefMin[i + 1] = std::min(nums[i], leftPrefMin[i]);
        }
        uint32_t suffIdx = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            rightSuffMax[suffIdx++] = std::max(rightSuffMax[suffIdx - 1], nums[i]);
        }
       
        for (std::size_t i = 1; i < nums.size(); i++) {
            if (nums[i] > leftPrefMin[i] && nums[i] < rightSuffMax[nums.size() - i]) {
                return true;
            }
        }
        return false;
        
    }
};
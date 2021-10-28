class Solution {
public:
    int rob(vector<int>& nums) {
        
        
        std::vector<uint16_t> dpInclusiveFirst(nums.size(), 0), dpNotInclusiveFirst(nums.size(), 0);
        
        dpInclusiveFirst[0] = nums[0];
       
        
        if (nums.size() > 1) {
            dpInclusiveFirst[1] = nums[1];
            dpNotInclusiveFirst[1] = nums[1];
        }
        if (nums.size() > 2) {
            dpNotInclusiveFirst[2] = nums[2];
        }
        
        
        int16_t maxIdx = 0;
        
        for (std::size_t i = 2; i < nums.size() - 1; i++) {
            if (dpInclusiveFirst[i - 2] > dpInclusiveFirst[maxIdx]) {
                maxIdx = i - 2;
            }
            dpInclusiveFirst[i] = dpInclusiveFirst[maxIdx] + nums[i];
        }
        maxIdx = 0;
        
        for (std::size_t i = 3; i < nums.size(); i++) {
            if (dpNotInclusiveFirst[i - 2] > dpNotInclusiveFirst[maxIdx]) {
                maxIdx = i - 2;
            }
            
            dpNotInclusiveFirst[i] = dpNotInclusiveFirst[maxIdx] + nums[i];
        }
        
        return std::max(*(std::max_element(dpInclusiveFirst.begin(), dpInclusiveFirst.end())), *(std::max_element(dpNotInclusiveFirst.begin(), dpNotInclusiveFirst.end())));
        
        
        
    }
};
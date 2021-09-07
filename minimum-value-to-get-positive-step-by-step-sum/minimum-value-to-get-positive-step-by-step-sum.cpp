class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        std::vector<int> pref(nums.size() + 1);
        int localMin = std::numeric_limits<int>::max();
        
        for (std::size_t i = 0; i < nums.size(); i++) {
            pref[i + 1] = pref[i] + nums[i];
            localMin = std::min(localMin, pref[i + 1]);
        }
        
        if (localMin > 0) {
            return 1;
        } else {
            return abs(localMin) + 1;
        }
        
        
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
    
        std::vector<int> preff(height.size() + 1), suff(height.size() + 1);
        preff[0] = 0;
        suff[0] = 0;
        
        for (std::size_t i = 0; i < height.size(); i++) {
            preff[i + 1] = std::max(preff[i], height[i]);
        }
        int tempSuffPointer = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            suff[tempSuffPointer + 1] = std::max(suff[tempSuffPointer], height[i]);
            tempSuffPointer++;
        }
        
        
        
        for (std::size_t i = 0; i < height.size(); i++) {
            int left_max = preff[i + 1];
            int right_max = suff[height.size() - i];
            
           ans += std::min(right_max, left_max) - height[i]; // -1
        }
        return ans;
    }
};
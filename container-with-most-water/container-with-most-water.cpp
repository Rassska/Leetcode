class Solution {
public:
    int maxArea(vector<int>& height) {
        std::size_t n = height.size();
        std::size_t ans = 0;
       
        
        std::size_t right = n - 1;
        std::size_t left = 0;
        
        while (left < right) {
            std::size_t currAns = (std::min(height[left], height[right]) * (right - left));
            ans = std::max(ans, currAns);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return ans;
        
        
        
        
    }
};
class Solution {
public:
    int minSwaps(vector<int>& data) {
        
        int totalOnes = 0;
        int maxOnesCurrSubarray = 0;
        int totalOnesCurrSubarray = 0;
        int ans = std::numeric_limits<int>::min();
        for (std::size_t i = 0; i < data.size(); i++) {
            if (data[i]) 
                totalOnes++;
        }
        
        int left = 0;
        int right = 0;
        
        while (right < data.size()) {
            if (data[right]) {
                totalOnesCurrSubarray++;
                maxOnesCurrSubarray = std::max(maxOnesCurrSubarray, totalOnesCurrSubarray);
            }
           
            if (right - left + 1 >= totalOnes) {
                if (data[left]) {
                    totalOnesCurrSubarray--;
                }
                left++;
            }
            
            right++;
        }
        return totalOnes - maxOnesCurrSubarray;
        
        
        
        
    }
};
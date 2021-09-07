class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int ans = 0;
        std::vector<int> prefixSum(gain.size() + 1);
        
        for (std::size_t i = 0; i < gain.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + gain[i];
        }
        
        for (std::size_t i = 0; i < gain.size(); i++) {
            ans = std::max(ans, prefixSum[i + 1]);
        }
        
        
        return ans;
        
        
    }
};
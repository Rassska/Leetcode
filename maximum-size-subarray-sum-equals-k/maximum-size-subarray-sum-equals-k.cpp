class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        int ans = 0;
        std::unordered_map<int, int> hashMap;
        int runningSum = 0;
        
        
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            
            if (runningSum == k) {
                ans = i + 1;
            }
            
             if (hashMap.find(runningSum - k) != hashMap.end()) {
                ans = std::max(ans, i - hashMap[runningSum - k]);
            }
            
            
            if (hashMap.find(runningSum) == hashMap.end()) {
                hashMap[runningSum] = i;
            }
            
        }
        
        return ans;
    }
};
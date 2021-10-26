class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        std::unordered_map <int, int> hashMap;
        
        for (auto num : nums) {
            hashMap[num]++;
        }
        int localMax = -1;
        int res = -1;
        
        for (auto it = hashMap.begin(); it != hashMap.end(); it++) {
            if (localMax < it -> second) {
                localMax = it -> second;
                res = it -> first;
            }
        }
        return res;
    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        std::unordered_map<int, int> hashMap;
        
        for (auto num : nums) {
            hashMap[num]++;
        }
        
        
        for (auto it = hashMap.begin(); it != hashMap.end(); it++) {
            if (it->second == 1) {
                return it->first;
            }
        }
        return -1;
    }
};
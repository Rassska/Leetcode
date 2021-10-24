class Solution {
public:
    
    void updateHashMap (std::unordered_map<int, int>& hashMap, int currElement) {
        hashMap[currElement]--;
        if (hashMap[currElement] == 0) {
            hashMap.erase(currElement);
        }
    }
    
    vector<int> findOriginalArray(vector<int>& changed) {
        
        std::sort(changed.begin(), changed.end());
        
        std::unordered_map<int, int> hashMap;
        std::vector<int> ans;
        
        for (int num : changed) {
            hashMap[num]++;
        }
        
        for (std::size_t i = 0; i < changed.size(); i++) {
            std::size_t currNum = changed[i];
            
            if (hashMap.find(currNum) != hashMap.end()) {
                updateHashMap(hashMap, currNum);
            
                if (hashMap.find(currNum * 2) == hashMap.end()) {
                    return std::vector<int>();
                }
                updateHashMap(hashMap, currNum * 2);
                ans.push_back(currNum);
            }
        }
        return ans;

    }
};
class Solution {
public:

    
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        int left = 0;
        int right = 0;
        int ans = 0;
        std::vector<std::pair<int, int>> hashMap(maxen);
        
        auto distinctCharAmount = [&](std::vector<std::pair<int, int>>& hashMap) {
            int distinctCharNum = 0;
            for (std::size_t i = 0; i < hashMap.size(); i++) {
                if (hashMap[i].second != 0) {
                    distinctCharNum++;
                }
            }
            return distinctCharNum;
        };
        
        while (right < s.size()) {
            hashMap[s[right]].second++;
            
            if (distinctCharAmount(hashMap) < 3) {
                ans = std::max(ans, right - left + 1);
            } else {
                while(distinctCharAmount(hashMap) > 2) {
                    hashMap[s[left]].second--;
                    left++;
                }
            }
            
            right++;
        }
        
        return ans;
        
        
    }
private:
    const int maxen = 300;
    
};
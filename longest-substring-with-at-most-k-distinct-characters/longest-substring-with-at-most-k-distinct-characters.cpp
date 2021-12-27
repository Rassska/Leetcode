class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        
        int left = 0;
        int ans = 0;
        std::unordered_map<char, int> hashMap;
        
        for (int i = 0; i < s.size(); i++) {
            hashMap[s[i]]++;
            
            while (hashMap.size() > k) {
                hashMap[s[left]]--;
                if (hashMap[s[left]] == 0) {
                    hashMap.erase(s[left]);
                }
                left++;
            }
            ans = std::max(ans, i - left + 1);
        }
        return ans;
    }
};
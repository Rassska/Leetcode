#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int numSplits(string s) {
        
        std::set<char> leftPref;
        std::unordered_map<char, int> hashMap;
        int ans = 0;
        for (std::size_t i = 0; i < s.size(); i++) {
            hashMap[s[i]]++;
        }
        
        for (std::size_t i = 0; i < s.size(); i++) {
            leftPref.insert(s[i]);
            
            if (hashMap[s[i]] == 1) {
                hashMap.erase(s[i]);
            } else {
                hashMap[s[i]]--;
            }
            
            if (leftPref.size() == hashMap.size()) {
                ans++;
            }
            
        }
        return ans;
        
        
        
    }
private:
    const char maxen = 26;
};
class Solution {
public:
    int longestPalindrome(string s) {
        
        
        std::unordered_map<char, int> hashTable;
        int ans = 0;
        bool isOddNumberPresent = false;
        for (auto ch : s) {
            hashTable[ch]++;
        }
        for (auto it = hashTable.begin(); it != hashTable.end(); it++) {
            if (!(it->second % 2)) {
                ans += it->second;
            } else {
                ans += it->second - 1;
                isOddNumberPresent = true;
            }
            
        }
        return ans + isOddNumberPresent;
    }
};
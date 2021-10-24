class Solution {
public:
    int numSplits(string s) {
        
        std::vector<std::vector<std::size_t>> leftPref(maxen, std::vector<std::size_t>(s.size() + 1, 0));
        std::vector<std::vector<std::size_t>> rightPref(maxen, std::vector<std::size_t>(s.size() + 1, 0));
        std::size_t ans = 0;
        
        for (std::size_t i = 0; i < s.size(); i++) {
            for (std::size_t j = 0; j < 26; j++) {
                if (j == s[i] - 'a') {
                    leftPref[s[i] - 'a'][i + 1] = leftPref[s[i] - 'a'][i] + 1;
                } else {
                    leftPref[j][i + 1] = leftPref[j][i];
                }
                
            }
            
        }
        
        std::size_t rightPrefPointer = 0;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            for (std::size_t j = 0; j < 26; j++) {
                if (j == s[i] - 'a') {
                    rightPref[s[i] - 'a'][rightPrefPointer + 1] = rightPref[s[i] - 'a'][rightPrefPointer] + 1;
                   
                } else {
                    rightPref[j][rightPrefPointer + 1] = rightPref[j][rightPrefPointer];
                }
                
            }
            rightPrefPointer++;
        }
        
        for (std::size_t i = 0; i < s.size(); i++) {
            std::size_t nonZerroCharsAmountLeftPref = 0;
            std::size_t nonZerroCharsAmountRightPref = 0;
            for (std::size_t j = 0; j < 26; j++) {
                if (leftPref[j][i + 1] != 0) {
                    nonZerroCharsAmountLeftPref++;
                }
            }
            for (std::size_t j = 0; j < 26; j++) {
                if (rightPref[j][s.size() - i - 1] != 0) {
                    nonZerroCharsAmountRightPref++;
                }
            }
            
            if (nonZerroCharsAmountRightPref == nonZerroCharsAmountLeftPref) 
                ans++;
        }
        return ans;
        
        
        
    }
private:
    const char maxen = 26;
};
class Solution {
public:
    int beautySum(string s) {
        std::size_t ans = 0;
        std::vector<std::vector<long>> pref(maxen, std::vector<long>(s.size()));
        
        for (long i = 0; i < 26; i++) {
            
            if (s[0] == 'a' + i) {
                pref[i][0] = 1;
            } else {
                pref[i][0] = 0;
            }
            
            for (long j = 1; j < s.size(); j++) {
                if (s[j] == 'a' + i) {
                    pref[i][j] = pref[i][j - 1] + 1;
                } else {
                    pref[i][j] = pref[i][j - 1];
                }
            }
        }
       
        for (long i = 0; i < s.size(); i++) {
            for (long j = i; j < s.size(); j++) {
                // substr [i; j)
                long currMax = std::numeric_limits<long>::min();
                long currMin = std::numeric_limits<long>::max();
             
                for (long t = 0; t < 26; t++) {
                    
                    long temp = (i) ? pref[t][j] - pref[t][i - 1] : pref[t][j];
                    if (!temp)
                        continue;
                    
                    currMax = std::max(currMax, temp);
                    currMin = std::min(currMin, temp);
                    
                }
                ans += currMax - currMin;
                
               
            }
            
            
            
        }
        return ans;
     
    }
private:
    const char maxen = 26;
};
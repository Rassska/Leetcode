/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    
    int getMatchDistance (const std::string& firstWord, const std::string& secondWord) {
        int ans = 0;
        
        for (std::size_t i = 0; i < firstWord.size(); i++) {
            if (firstWord[i] == secondWord[i]) 
                ans++;
        }
        return ans;
    }
    
    
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int length = wordlist.size();
        
        for (unsigned char i = 0; i < 10; ++i) {
            int pos = length / 2;
            std::string selectedWord = wordlist[pos];
            int numMasterMatch = master.guess(selectedWord);
            if (numMasterMatch == 6) {
                return ;
            }
            for (int k = 0; k < length; k++) {
                if (getMatchDistance(selectedWord, wordlist[k]) != numMasterMatch) {
                    length--;
                    wordlist[k] = wordlist[length];
                }
                
            }
            
        }
        
    }
};
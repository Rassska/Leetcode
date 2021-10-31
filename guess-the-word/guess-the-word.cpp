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
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        srand(1); 
        random_shuffle(wordlist.begin(), wordlist.end()); 
        for (int step = 0; step < 10; ++step) 
            if (wordlist.size()) {
                string w = wordlist.back(); 
                wordlist.pop_back(); 
                int m = master.guess(w); 
                vector<string> temp; 
                for (auto& ww : wordlist) {
                    int cnt = 0; 
                    for (int i = 0; i < w.size(); ++i) 
                        if (w[i] == ww[i]) ++cnt; 
                    if (cnt == m) temp.push_back(ww); 
                }
                wordlist = temp; 
            }
    }
};
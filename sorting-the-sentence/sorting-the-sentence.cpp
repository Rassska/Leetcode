class Solution {
public:
    string sortSentence(string s) {
        
        std::map<int, std::string> hashMap;
        std::string currWord = "";
        for (std::size_t i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                hashMap[s[i] - '0'] = currWord;
                currWord = "";
            } else if (s[i] != ' ') {
                currWord += s[i];
            }
        }
        
        
        std::string ans = "";
        
        for (auto it = hashMap.begin(); it != hashMap.end(); it++) {
            if (it -> second != "") {
                ans += it->second;
            }
            if (ans.size() != 0) {
                ans += ' ';
            }
        }
        ans.erase(ans.begin() + ans.size() - 1);
        
        return ans;
    }
    
};
class Solution {
public:
    bool wordPattern(string pattern, string s) {
    
        
        std::unordered_map<char, std::string> hashMap;
        std::vector<std::string> strings;
        std::string currString = "";
        for (std::size_t i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                strings.push_back(currString);
                currString = "";
            } else {
                currString += s[i];
            }
        }
        if (!currString.empty()) {
            strings.push_back(currString);
        }
        if (pattern.size() != strings.size()) {
            return false;
        }
        
        for (std::size_t i = 0; i < pattern.size(); i++) {
            if (hashMap.find(pattern[i]) != hashMap.end()) {
                if (hashMap[pattern[i]] != strings[i]) {
                    return false;
                }
            } else {
                for (auto it : hashMap) {
                    if (it.second == strings[i]) {
                        return false;
                    }
                }
                hashMap[pattern[i]] = strings[i];
            }
            
        }
        return true;
    }
};
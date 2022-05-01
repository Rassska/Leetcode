class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        std::stack<char> firstString, secondString;
      
        for (std::size_t i = 0; i < s.size(); i++) {
            if (s[i] == '#' && firstString.size() > 0) {
                firstString.pop();
                continue;
            } else if (s[i] != '#')
                firstString.push(s[i]);
        }
        
        for (std::size_t i = 0; i < t.size(); i++) {
            if (t[i] == '#' && secondString.size() > 0) {
                secondString.pop();
                continue;
            } else if (t[i] != '#')
                secondString.push(t[i]);
        }
        
        
        if (firstString == secondString) {
            return true;
        } else {
            return false;
        }
        
        
        
    }
};
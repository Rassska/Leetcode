class Solution {
public:
    
    std::stack<char> build (std::string currString) {
        std::stack<char> st;
        
        for (auto ch : currString) {
            if (ch != '#') {
                st.push(ch);
            } else if (!st.empty()) {
                st.pop();
            }
        }
        return st;
        
    }
    bool backspaceCompare(string s, string t) {
        
        return build(s) == build(t);
        
    }
};

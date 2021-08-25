class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows <= 1) {
            return s;
        }
        
        std::vector<std::string> stringsHolder (numRows, "");
        
        for (int i = 0, row = 0, step = 1; i < s.size(); i++) {
            
            stringsHolder[row] += s[i];
            
            if (row == 0) {
                step = 1;
            } 
            if (row == numRows - 1) {
                step = -1;
            };
            
            row += step;
        }
        
        std::string ans;
        for (auto currString : stringsHolder) 
            ans += currString;
        
        return ans;
    }
};
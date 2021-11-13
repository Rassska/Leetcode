
class Solution {
public:
    string addStrings(string num1, string num2) {
        
        std::string stringSum = "";
        
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        
        if (num1.size() < num2.size()) {
            std::swap(num1, num2);
        }
        uint32_t num2Idx = 0;
        bool remaining = false;
        for (std::size_t i = 0; i < num1.size(); i++) {
            if (num2Idx >= num2.size()) {
                stringSum.push_back('0' + (num1[i] - '0' + remaining) % 10);
                if ((num1[i] - '0' + remaining) / 10) {
                    remaining = true;
                } else {
                    remaining = false;
                }
                continue;
            }
            if ((num1[i] - '0') + (num2[num2Idx] - '0') + remaining <= 9) {
                stringSum.push_back(num1[i] - '0' + num2[num2Idx++] + remaining);
                remaining = false;
                
            } else {
                stringSum.push_back('0' + ((num1[i] - '0' + num2[num2Idx++] - '0' + remaining) % 10));
                remaining = true;
            }
        }
        if (remaining)  stringSum.push_back('1');
        std::reverse(stringSum.begin(), stringSum.end());
        return stringSum;
        
        
    }
};
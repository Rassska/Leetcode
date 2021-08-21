class Solution {
public:
    int myAtoi(string s) {
        
        std::size_t iterator = 0;
        int isPositive = 1;
        long long ans = 0;
        
        while (iterator < s.size()) {
            if (s[iterator] == ' ') {
                iterator++;
            } else {
                break;
            }
        }
        
        if (s[iterator] == '-' || s[iterator] == '+') {
            isPositive = s[iterator] == '-' ? -1 : 1;
            iterator++;
        }
        
    
        while(iterator < s.size()) {
            if (std::isdigit(s[iterator])) {
                ans *= 10;
                ans += s[iterator] - '0';
                if (ans * isPositive > INT_MAX) {
                    return INT_MAX;
                } else if (ans * isPositive < INT_MIN) {
                    return INT_MIN;
                }
                
            } else {
                break;
            }
            iterator++;
        }
        return ans * isPositive;
    }
};
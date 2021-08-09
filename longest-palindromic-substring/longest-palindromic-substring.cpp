class Solution {
public:
    string longestPalindrome(string s) {

        std::size_t n = s.size();
       
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n));
        
        for (std::size_t i = 0; i < n; i++) {
            dp[i][i] = true;
        }
            

        std::string ans = "";
        ans += s[0];

        for (int start = n - 1; start >= 0; start--){
            for (int end = start + 1; end < n; end++){
                if (s[start] == s[end]){
                    if (end - start == 1 || dp[start + 1][end - 1]){
                        dp[start][end] = true;

                        if (ans.size() < end - start + 1)
                            ans = s.substr(start, end - start + 1);
                    }
                }
            }
        }
        return ans;
    }
};
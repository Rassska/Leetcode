class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        std::string ans = "";
        std::sort(strs.begin(), strs.end());
        
        for (int i = 0; i < strs[0].size(); i++) {
            if (strs[0][i] == strs[strs.size() - 1][i]) {
                ans.push_back(strs[0][i]);
            } else {
                break;
            }
        }
        return ans;
    }
};
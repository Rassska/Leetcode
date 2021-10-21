class Solution {
public:
    
    int dfs (std::string currString, std::unordered_set<std::string>& hashSet, std::unordered_map<std::string, int>& memo) {
        
       
        if (memo.find(currString) != memo.end()) {
            return memo[currString];
        }
        
        int maxLength = 1;
            
        
        for (std::size_t i = 0; i < currString.size(); i++) {
            std::string selected = currString.substr(0, i) + currString.substr(i + 1);
            if (hashSet.find(selected) != hashSet.end()) {
                maxLength = std::max(maxLength, 1 + dfs(selected, hashSet, memo));
            }

        }
        memo[currString] = maxLength;
            
        
        return maxLength;
    }
    
    int longestStrChain(std::vector<std::string>& words) {
        int ans = 0;
        
        std::unordered_set<std::string> hashSet;
        std::unordered_map<std::string, int> memo;
        
        hashSet.insert(words.begin(), words.end());
       
        for (std::size_t i = 0; i < words.size(); i++) {
            ans = std::max(ans, dfs(words[i], hashSet, memo));
        }
        return ans;
    }

};
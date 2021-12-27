class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        
        
        auto mergeIntervals = [&](std::vector<std::vector<int>>& ans) {
            std::vector<std::vector<int>> mergedAns;
      
            
            for (std::size_t i = 0; i < ans.size(); i++) {
                while(i < ans.size() - 1 && ans[i + 1][0] == ans[i][0]) {
                    ans[i + 1][1] += ans[i][1];
                    i++;
                }
                mergedAns.push_back(ans[i]);
            }
            
            return mergedAns;
        };
        
        int firstP = 0;
        int secondP = 0;
        std::vector<std::vector<int>> ans;
        
        while (firstP < encoded1.size() && secondP < encoded2.size()) {
            std::vector<int> currPair;
            
            int currPairEndMin = std::min(encoded1[firstP][1], encoded2[secondP][1]); // 3
            
            currPair.push_back(encoded1[firstP][0] * encoded2[secondP][0]);
            currPair.push_back(currPairEndMin);
            ans.push_back(currPair);
            
            if (encoded1[firstP][1] == currPairEndMin) {
                firstP++;
            } else {
                encoded1[firstP][1] -= currPairEndMin;
            }
            
            if (encoded2[secondP][1] == currPairEndMin) {
                secondP++;
            } else {
                encoded2[secondP][1] -= currPairEndMin;
            }
            
            
        }
        
        ans = mergeIntervals(ans);
        
        return ans;
        
    }
};
class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        
        
        
        int firstP = 0;
        int secondP = 0;
        int prevProduct = 0;
        int currProduct = 0;
        std::vector<std::vector<int>> ans;
        
        while (firstP < encoded1.size() && secondP < encoded2.size()) {
            std::vector<int> currPair;
            
            int currPairEndMin = std::min(encoded1[firstP][1], encoded2[secondP][1]); // 3
            currProduct = encoded1[firstP][0] * encoded2[secondP][0];
            
            
            if (ans.size() > 0 && currProduct == prevProduct) {
                ans[ans.size() - 1][1] += currPairEndMin;
            } else {
                ans.push_back({currProduct, currPairEndMin});
            }
            
            prevProduct = currProduct;
            
            encoded1[firstP][1] -= currPairEndMin;
            encoded2[secondP][1] -= currPairEndMin;
            
            if (encoded1[firstP][1] == 0) firstP++;
            if (encoded2[secondP][1] == 0) secondP++;
            
            
        }
        
        
        return ans;
        
    }
};
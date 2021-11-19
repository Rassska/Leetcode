class Solution {
public:
    
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        
        std::vector<std::vector<int>> preff(colors.size() + 2, std::vector<int>(3, INT_MAX)), suff(colors.size() + 2, std::vector<int>(3, INT_MAX));
        
        for (std::size_t i = 0; i < colors.size(); i++) {
            preff[i + 1][0] = preff[i][0];
            preff[i + 1][1] = preff[i][1];
            preff[i + 1][2] = preff[i][2];
            
            if (colors[i] == 1) {
                preff[i + 1][0] = i;
            } else if (colors[i] == 2) {
                preff[i + 1][1] = i;
            } else {
                preff[i + 1][2] = i;
            }
        }
        
        uint32_t suffIdx = 0;
        
        for (int i = colors.size() - 1; i >= 0; i--) {
            suff[suffIdx + 1][0] = suff[suffIdx][0];
            suff[suffIdx + 1][1] = suff[suffIdx][1];
            suff[suffIdx + 1][2] = suff[suffIdx][2];
            
            if (colors[i] == 1) {
                suff[suffIdx + 1][0] = i;
            } else if (colors[i] == 2) {
                suff[suffIdx + 1][1] = i;
            } else {
                suff[suffIdx + 1][2] = i;
            }
            suffIdx++;
        }
        std::vector<int> ans;
       
        for (std::size_t i = 0; i < queries.size(); i++) {
            int currQueryIndex = queries[i][0];
            int currQueryValue = queries[i][1];
            int preffValue = INT_MAX;
            int suffValue = INT_MAX;
            
            if (preff[currQueryIndex + 1][currQueryValue - 1] != INT_MAX)
                preffValue = abs(currQueryIndex - preff[currQueryIndex + 1][currQueryValue - 1]);

            if (suff[colors.size() - currQueryIndex][queries[i][1] - 1] != INT_MAX)
                suffValue = abs(currQueryIndex - suff[colors.size() - currQueryIndex][queries[i][1] - 1]);
            
            int minSteps = std::min(preffValue, suffValue);
            if (minSteps == INT_MAX) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(minSteps);
        }
        return ans;
        
    }
};
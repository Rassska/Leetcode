class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    
        
        
        int left = 0;
        int right = mat[0].size();
        int line = 0;
        while (left < right) {
            std::pair<int, int> mid = {0, left + (right - left) / 2};
            int midValue = mat[mid.first][mid.second];
            
            for (std::size_t i = 0; i < mat.size(); i++) {
                if (mat[i][mid.second] > midValue) {
                    mid.first = i;
                    line = i;
                    midValue = mat[mid.first][mid.second];
                }
            }
            
            if (mid.second > 0 && mat[mid.first][mid.second] < mat[mid.first][mid.second - 1]) {
                right = mid.second;
            } else if (mid.second + 1 < mat[0].size() && mat[mid.first][mid.second] < mat[mid.first][mid.second + 1]) {
                left = mid.second + 1;
            } else {
                return std::vector<int>({mid.first, mid.second});
            }

        }
        
        return std::vector<int>({line, left});
     
    }
    
};



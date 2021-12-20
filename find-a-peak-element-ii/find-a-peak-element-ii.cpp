class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    
        
        
        int left = 0;
        int right = mat[0].size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int maxNumRowIndex = 0;
            
            for (int i = 0; i < mat.size(); i++) {
                if (mat[i][mid] > mat[maxNumRowIndex][mid]) {
                    maxNumRowIndex = i;
                }
            }
            
            if ((mid == 0 || mat[maxNumRowIndex][mid] > mat[maxNumRowIndex][mid - 1]) && (mid == mat[0].size() - 1 || mat[maxNumRowIndex][mid] > mat[maxNumRowIndex][mid + 1])) {
                return std::vector<int>({maxNumRowIndex, mid});
            } else if (mid > 0 && mat[maxNumRowIndex][mid] < mat[maxNumRowIndex][mid - 1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }

        }
        return std::vector<int>({-1, -1});
        
      
     
    }
    
};



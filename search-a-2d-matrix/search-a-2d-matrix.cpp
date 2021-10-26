class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for (std::size_t i = 0; i < matrix.size(); i++) {
            int left = 0;
            int right = matrix[i].size() - 1;
            
            while (left <= right) {
                int mid = (left + right) / 2;
                
                if (matrix[i][mid] == target) {
                    return true;
                } else if (matrix[i][mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return false;
        
        
    }
};
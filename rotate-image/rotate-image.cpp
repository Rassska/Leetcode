class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int matrixSideLength = matrix[0].size();
        
        for (std::size_t i = 0; i < matrixSideLength; i++) {
            for (std::size_t j = 0; j < i; j++) {
                swap(matrix[j][i], matrix[i][j]);
            }
        }
        
        for (std::size_t i = 0; i < matrixSideLength; i++) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
        
        
        
        
        
        
    }
};
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        
        /*
            [[1,2,3],
             [4,5,6],
             [7,8,9]]
                
            [[1, 4, 7]
             [2, 5, 8]
             [3, 6, 9]]
        
        */
        
        
        for (std::size_t i = 0; i < matrix.size(); i++) {
            for (std::size_t j = i; j < matrix[i].size(); j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (std::size_t i = 0; i < matrix.size(); i++) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};
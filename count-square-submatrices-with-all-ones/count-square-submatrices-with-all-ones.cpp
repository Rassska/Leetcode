class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        
        /*
            *Clarifying the problem statement
            
            1. 1 <= matrix.length <= 300
            2. 1 <= matrix[i].length <= 300
            3. 0 <= matrix[i][j] <= 1
            
            return the amount of squares submatrices with only ones (int)
            
            
            * Initial thoughts
            
            1. Iterating through the whole matrix and from each angle count amount of squares submatrices with only ones
            2. We need to return a sum of them
            3. We need to count squares submatrices, if matrix[i][j] == 1
            
            ***
                [0,1,1,1],
                [1,1,1,1],
                [0,1,1,1].
                
                1 + 1 + 1 + 1 + 1 + .... = 15
                
            ***
            
            * Complexity Analysis
            
            1. Time complexity: O(n * m)
            2. Space somplexity: O(1)
            
        
        */
        
        std::size_t ans = 0;
        
        for (std::size_t i = 0; i < matrix.size(); i++) {
            for (std::size_t j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 1) {
                    if (i > 0 && j > 0) {
                        matrix[i][j] += std::min(matrix[i - 1][j], std::min(matrix[i - 1][j - 1], matrix[i][j - 1]));
                    }
                    ans += matrix[i][j];
                    
                } 
            }
        }
        return ans;
    }
};
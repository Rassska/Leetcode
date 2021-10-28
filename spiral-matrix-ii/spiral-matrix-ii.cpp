class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        std::vector<std::vector<int>> spiralMatrix(n, std::vector<int>(n, 0));
        
        
        int currValue = 1;
        
        int rowStart = 0, rowEnd = n - 1;
        int colStart = 0, colEnd = n - 1;
        
        
        while (rowStart <= rowEnd && colStart <= colEnd) {
            
            for (int i = colStart; i <= colEnd; i++) 
                spiralMatrix[rowStart][i] = currValue++;
            rowStart++;
            
            for (int i = rowStart; i <= rowEnd; i++) 
                spiralMatrix[i][colEnd] = currValue++;
            colEnd--;
            
            for (int i = colEnd; i >= colStart; i--)
                spiralMatrix[rowEnd][i] = currValue++;
            rowEnd--;
            
            for (int i = rowEnd; i >= rowStart; i--)
                spiralMatrix[i][colStart] = currValue++;
            colStart++;
            
            
        }
        return spiralMatrix;
        
        // 0 - right
        // 1 - down
        // 2 - left
        // 3 - up
        
        
        
        
        
    }
};
class Solution {
public:
    
    int countCurrCellPerimeter(std::vector<std::vector<int>>& grid, int i, int j) {
        int maxPerimeter = 4;
        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            maxPerimeter--;
        }
        if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
            maxPerimeter--;
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            maxPerimeter--;
        }
        if (j + 1 < grid[i].size() && grid[i][j + 1] == 1) {
            maxPerimeter--;
        }
        return maxPerimeter;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        for (std::size_t i = 0; i < grid.size(); i++) {
            for (std::size_t j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    ans += countCurrCellPerimeter(grid, i, j);
                }
            }
        }        
        
        return ans;
    }
};
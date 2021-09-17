class Solution {
public:
    
    void island(vector<vector<char>>& grid, int i, int j) {
        if (i >= grid.size() || i < 0 || j >= grid[i].size() || j < 0) {
            return;
        }
        
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
        } else {
            return;
        }
        
        // right
        island(grid, i, j + 1);
        // down
        island(grid, i + 1, j);
        // left
        island(grid, i, j - 1);
        // up
        island(grid, i - 1, j);
        
        
        
        
    }
        
    int numIslands(vector<vector<char>>& grid) {
        
        std::size_t ans = 0;
        for (std::size_t i = 0; i < grid.size(); i++) {
            for (std::size_t j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    island(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
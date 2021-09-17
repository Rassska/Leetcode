class Solution {
public:
    
    int dfs (std::vector<std::vector<int>>& grid, int i, int j, int localAns) {
        
        if (i >= grid.size() || j >= grid[i].size() || j < 0 || i < 0) {
            return 0;
        }
        if (grid[i][j] == 1) {
            grid[i][j] = 0;
            localAns = 1 + dfs(grid, i + 1, j, localAns) + dfs(grid, i - 1, j, localAns) + dfs(grid, i, j + 1, localAns) + dfs(grid, i, j - 1, localAns);
        }
        return localAns;
       
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        for (std::size_t i = 0; i < grid.size(); i++) {
            for (std::size_t j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    ans = std::max(ans, dfs(grid, i, j, 0));
                }
            }
        }
        return ans;
        
    }
};
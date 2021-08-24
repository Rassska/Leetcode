class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        std::size_t ans = 0;
        std::size_t n = grid.size();
        std::size_t m = grid[0].size();

        for (std::size_t i = 0; i < n; i++) {
            for (std::size_t j = 0; j < m; j++) {
                if (grid[i][j] < 0) {
                    ans++;
                }
            }
        }
        return ans;
    }

};
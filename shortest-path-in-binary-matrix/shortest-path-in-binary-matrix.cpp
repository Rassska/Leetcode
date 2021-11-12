class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        std::queue<std::pair<int, int>> q;
        std::vector<std::pair<int, int>> neighbours = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        if (grid[0][0] != 0 || grid[grid.size() - 1][grid[0].size() - 1] != 0) {
            return -1;
        }
        q.push({0, 0});
        grid[0][0] = 1;
        
        while (!q.empty()) {
            int node_i = q.front().first;
            int node_j = q.front().second;
            q.pop();
            int distance = grid[node_i][node_j];
            if (node_i == grid.size() - 1 && node_j == grid[node_i].size() - 1) {
                return distance;
            }
            
            for (std::size_t i = 0; i < neighbours.size(); i++) {
                int newRow = node_i + neighbours[i].first;
                int newCol = node_j + neighbours[i].second;
                if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[newRow].size() || grid[newRow][newCol] != 0) {
                    continue;
                }
                q.push({newRow, newCol});
                grid[newRow][newCol] = distance + 1;
            }
            
           
        }
        return -1;
       
        
        
        
    }
};
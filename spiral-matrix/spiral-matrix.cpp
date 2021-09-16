class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        std::vector<int> ans;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        
        int right = 0;
        int down = 1;
        int left = m - 1;
        int up = n - 2;
        int cnt = 0;
        while (ans.size() < n * m) {
            
            for (std::size_t i = right; i <= left; i++) {
                ans.push_back(matrix[down - 1][i]);       
            }
            if (ans.size() == n * m) break;
            
            for (std::size_t i = down; i <= up; i++) {
                ans.push_back(matrix[i][left]);
            }
            if (ans.size() == n * m) break;
            
            for (int i = left; i >= right; i--) {
                ans.push_back(matrix[up + 1][i]);    
            }
            if (ans.size() == n * m) break;
            for (int i = up; i >= down; i--) {
                ans.push_back(matrix[i][right]);    
            }
            if (ans.size() == n * m) break;
            
            
            
            right++;
            down++;
            left--;
            up--;
            
        }
        
        return ans;
        
        
    }
};
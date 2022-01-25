class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool ans = true;
       
        for (std::size_t i = 0; i < coordinates.size() - 2; i++) {
            int x1 = coordinates[i][0];     int y1 = coordinates[i][1];
            int x2 = coordinates[i + 1][0]; int y2 = coordinates[i + 1][1];
            int x3 = coordinates[i + 2][0]; int y3 = coordinates[i + 2][1];
            
            if ((x3 - x2) * (y2 - y1) != (x2 - x1) * (y3 - y2)) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};
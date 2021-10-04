class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        
        if (points.size() == 1) {
            return true;
        }
        
        std::unordered_map<int, std::set<int>> unMap;
        int maxX = points[0][0];
        int minX = maxX;
        for (std::size_t i = 0; i < points.size(); i++) {
            if (points[i][0] > maxX) {
                maxX = points[i][0];
            }
            if (points[i][0] < minX) {
                minX = points[i][0];
            }

            unMap[points[i][1]].insert(points[i][0]);
        }
        
        double lineX = (maxX + minX) / 2.0;
        
        for (auto it = unMap.begin(); it != unMap.end(); it++) {
            std::set<int>& currYSet = it->second;
            
            
            for (auto start = currYSet.begin(), end = currYSet.end(); start != end; ++start) {
                if (((*start + *(--end)) / 2.0) != lineX) {
                    return false;
                }
                if (start == end) break;
            }
            
            
        }
        return true;
        
    }
};
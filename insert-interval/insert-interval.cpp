class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        std::vector<std::vector<int>> res;
        
        for (std::size_t i = 0; i < intervals.size(); i++) {
            if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            }
        }
        
        for (std::size_t i = 0; i < intervals.size(); i++) {
            if (newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1]) {
                newInterval[0] = intervals[i][0];
            }
            if (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) {
                newInterval[1] = intervals[i][1];
            }
        }
       
        res.push_back(newInterval);
        for (std::size_t i = 0; i < intervals.size(); i++) {
            if (newInterval[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            }
        }
        
        
        
        return res;
        
    }
};
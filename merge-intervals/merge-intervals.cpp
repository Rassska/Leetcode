class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        std::vector<std::vector<int>> mergedIntervals;
        std::sort(intervals.begin(), intervals.end());
        
        std::size_t currMergeInterval = 0;
        mergedIntervals.push_back(intervals[0]);
        for (std::size_t i = 1; i < intervals.size(); i++) {
            
            // intervals[i][0] - open
            // intervals[i][1] - close
            
            if (mergedIntervals[currMergeInterval][1] >= intervals[i][0]) {     
                mergedIntervals[currMergeInterval][1] = std::max(intervals[i][1], mergedIntervals[currMergeInterval][1]);
            } else {
                mergedIntervals.push_back(intervals[i]);
                currMergeInterval++;
            }
            
            
        }
        return mergedIntervals;
        
        
    }
};
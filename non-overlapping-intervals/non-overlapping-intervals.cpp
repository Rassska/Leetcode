class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        std::sort(intervals.begin(), intervals.end());
      
        int ans = 0;
        int prev = 0;
        for (std::size_t i = 1; i < intervals.size(); i++) {
             if (intervals[i][0] < intervals[prev][1]) {
                 if (intervals[prev][1] > intervals[i][1]) {
                     prev = i;
                 }
                 ans++;
             } else {
                 prev = i;
             }
            
        }
        
        return ans;
        
    }
};
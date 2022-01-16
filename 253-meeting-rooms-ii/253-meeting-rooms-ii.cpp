class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        
        for (std::size_t i = 0; i < intervals.size(); i++) {
            int startTime = intervals[i][0];
            int endTime = intervals[i][1];
            
            while (minHeap.size() != 0 && startTime >= minHeap.top().first) {
                minHeap.pop();
            }
            minHeap.push({endTime, startTime});
           
            minRoomRequired = std::max(minRoomRequired, (int)minHeap.size());
        }
        return minRoomRequired;
        
    }
private:
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
    int minRoomRequired = 0;
};
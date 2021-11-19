class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        
        uint32_t firstP = 0, secondP = 0;
        std::vector<int> availableInterval;
        std::sort(slots1.begin(), slots1.end());
        std::sort(slots2.begin(), slots2.end());
        while (firstP < slots1.size() && secondP < slots2.size()) {
            if (slots1[firstP][0] >= slots2[secondP][0] 
                && slots1[firstP][0] + duration <= slots2[secondP][1] 
                && slots1[firstP][0] + duration <= slots1[firstP][1]){
                
                availableInterval.push_back(slots1[firstP][0]);
                availableInterval.push_back(slots1[firstP][0] + duration);
                break;
            } else if (slots1[firstP][0] < slots2[secondP][0] 
                       && slots2[secondP][0] + duration <= slots1[firstP][1] 
                       && slots2[secondP][0] + duration <= slots2[secondP][1]) {
                
                availableInterval.push_back(slots2[secondP][0]);
                availableInterval.push_back(slots2[secondP][0] + duration);
                break;
            }
            
            if (slots1[firstP][1] >= slots2[secondP][1]) {
                secondP++;
            } else {
                firstP++;
            }
        }
        
        return availableInterval;
        
        
    }
};
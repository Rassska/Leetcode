class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        
        std::vector<int> ans;
        
        std::sort(slots1.begin(), slots1.end());
        std::sort(slots2.begin(), slots2.end());
        
        std::size_t firstP = 0, secondP = 0;
        
        while (firstP < slots1.size() && secondP < slots2.size()) {
            // slots1[firstP][0] - start
            // slots1[firstP][1] - end
            
            int currCompStart = std::max(slots1[firstP][0], slots2[secondP][0]); // 10
            int currCompEnd = std::min(slots1[firstP][1], slots2[secondP][1]); // 15
            
            if (currCompStart + duration <= currCompEnd) {
                ans.push_back(currCompStart);
                ans.push_back(currCompStart + duration);
                break;
                
            }
            
            if (slots1[firstP][1] >= slots2[secondP][1]) {
                secondP++;
            } else {
                firstP++;
            }
        }
        
        return ans;
    }
};
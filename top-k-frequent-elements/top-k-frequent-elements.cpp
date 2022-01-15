

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        for (auto& num : nums){
            hashMap[num]++;
        }
        
        for (auto& currPair : hashMap) {
            maxHeap.push(std::make_pair(currPair.second, currPair.first));
        }
        
        while (k--) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
        
    }
private:
    std::unordered_map<int, int> hashMap;
    std::priority_queue<std::pair<int, int>> maxHeap;
    std::vector<int> ans;
};
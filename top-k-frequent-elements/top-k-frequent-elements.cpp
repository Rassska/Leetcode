class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        std::unordered_map <int, int> hashTable;
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        std::vector<int> ans;
        
        for (int num : nums) {
            hashTable[num]++;
        }
        
        for (std::pair<int, int> currPair : hashTable) {
            buckets[currPair.second].push_back(currPair.first);
        }
        
        for (std::size_t i = buckets.size() - 1; i != -1; i--) {
            if (ans.size() < k) {
                ans.insert(std::end(ans), std::begin(buckets[i]), std::end(buckets[i]));
            } else {
                break;
            }
        }
        return ans;
        
        
        
    }
};
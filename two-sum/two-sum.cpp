class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hashTable;
        std::vector<int> result;
        for (std::size_t i = 0; i < nums.size(); i++) {
            hashTable[nums[i]] = i;
        }
        
        for (std::size_t i = 0; i < nums.size(); i++) {
            if ((hashTable.find(target - nums[i]) != hashTable.end())
            && (hashTable.find(target - nums[i]) -> second != i)) {
                result.push_back(i);
                result.push_back(hashTable.find(target - nums[i])->second);
                break;
            } 
        }
        return result;
        
        
    }
};
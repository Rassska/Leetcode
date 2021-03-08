class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::vector <int> hashTable(nums.size() + 1);
        std::vector <int> answer;
        for (std::size_t i = 0; i < nums.size(); i++) {
            int key = nums[i];
            hashTable[key]++; // counting amount of keys;   
        }
        
        for (std::size_t i = 1; i < hashTable.size(); i++) {
            if (hashTable[i] == 0) {
                answer.push_back(i);
            }
        }
        return answer;
        
    }
};

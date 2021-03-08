class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        std::vector <int> answer;
        for (std::size_t i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for (std::size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1){
                answer.push_back(i + 1);
            }
        }
    
        return answer;
        
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
       
        int left = 0, right = nums.size() - 1, curr = 0;
        
        while (curr <= right) {
            if (!nums[curr]) {
                std::swap(nums[curr++], nums[left++]);
            } else if (!(nums[curr] % 2)){
                std::swap(nums[curr], nums[right--]);
            } else {
                curr++;
            }
        }
        
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        /*
            1) Integers in each row are sorted from left to right.
            2) The first integer of each row is greater than the last integer of the previous row.
        
        
        */
        
        std::vector<int> nums;
        
        for (std::size_t i = 0; i < matrix.size(); i++) {
            for (std::size_t j = 0; j < matrix[i].size(); j++) {
                nums.push_back(matrix[i][j]);
            }
        }
        
        for (std::size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return true;
            }
        }
        return false;
    }
};
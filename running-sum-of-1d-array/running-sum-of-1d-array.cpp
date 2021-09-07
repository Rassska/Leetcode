class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        
        /*
        
            1) Claryfying the problem
            1.1) 1 <= nums.size() <= 10^3
            1.2) -10^6 <= nums[i] <= 10^6
            1.3) return the running sum e.g. runningSum[i] = sum (nums[0]...nums[i])
            
            
            2) Initial approaches
            2.1) iterating though the array with local sum, where local sum is sum till i in nums
            2.1) nums[1, 2, 3, 4], i = 0, localSum = 1; i = 1, localSum = 3
            
            3) Solution
            3.1)
        */
        
        std::vector<int> res;
        int localSum = 0;
        for (std::size_t i = 0; i < nums.size(); i++) {
            localSum += nums[i];
            res.push_back(localSum);
        }
        
        return res;
        
        /*
    
            4) Debugging
            4.1) nums[1, 1, 1, 1, 1]
                i = 0 => localSum = 1, res = {1}
                i = 1 => localSum = 2, res = {1, 2}
                i = 2 => localSum = 3, res = {1, 2, 3}
                ...
                i = 4 => localSum = 5, res = {1, 2, 3, 4, 5}        
        */
        
            
        
    }
};
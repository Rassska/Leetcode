class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
       
        
        int step = 1;
        int globalSum = 0;
        std::vector<int> prefixSum(arr.size() + 1, 0);
        
        for (std::size_t i = 0; i < arr.size(); i++) {
            prefixSum[i + 1] = arr[i] + prefixSum[i];
        }
        
        while (step <= arr.size()) { // O(arr.size())
            int localSum = 0;
            int r = step;
            int l = 0;
            
            while (r <= arr.size()) {
                localSum += prefixSum[r++] - prefixSum[l++];
            }
            globalSum += localSum;
            
            step += 2; // step = 3
        }
        
        return globalSum;
        
        /*
            arr = [1,4,2,5,3]
            *****************
                step = 1: localSum = 1 + 4 + 2 + 5 + 3; globalSum = 15
                step = 3: localSum = 7 + 11 + 10; globalSum = 28
                step = 5: 
        
            *****************
            Time complexity - O(arr.size() * arr.size() * arr.size()) => O(arr.size()^3)
            Space complexity - O(1)
            
            prefixSum[i] = (sum[0]...sum[i]);
            
            arr = [1,4,2,5,3]
            *****************
            step = 1: localSum = 1 + 4 + 2 + 5
            
            
        */
        
        
    }
};
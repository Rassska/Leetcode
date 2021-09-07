class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
       
        
        int step = 1;
        std::size_t globalSum = 0;
        
        while (step <= arr.size()) {
            std::size_t localSum = 0;
            
            for(std::size_t i = 0; i < arr.size() - step + 1; i++) {
                std::size_t currArrSum = 0;
                for(std::size_t j = i; j < i + step; j++) {
                    currArrSum += arr[j];
                }
                localSum += currArrSum;
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
        
        */
        
        
    }
};
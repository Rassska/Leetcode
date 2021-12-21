class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        int ans = 0;
        
        for (std::size_t i = 0; i < arr.size(); i++){
            for (std::size_t j = i; j < arr.size(); j++){
                if ((j + 1 - i) % 2 == 0) continue;
                int currSubArraySum = 0;
                for (std::size_t k = i; k <= j; k++){
                    currSubArraySum += arr[k];
                }
                ans += currSubArraySum;
            }
        }
        return ans;
        
    }
};
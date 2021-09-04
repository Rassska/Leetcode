class Solution {
public:
    int countPrimes(int n) {
        
        std::vector<bool> prime(n + 1, true);
        prime[0] = false;
        prime[1] = false;
        
        std::size_t ans = 0;
        
        for (std::size_t i = 2; i <= n; i++) {
            if (prime[i]) {
                if (i * i <= n) {
                    for (std::size_t j = i * i; j <= n; j += i) {
                        prime[j] = false;
                    }
                }
            }
        }
        
        for (std::size_t i = 2; i < n; i++) {
            if (prime[i]) {
                ans++;
            }
        }
        return ans;
        
        
        
        
        
    }
};
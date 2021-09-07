class Solution {
public:
    
    int fibCount(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            return fibCount (n - 1) + fibCount(n - 2);
        }
    }
    
    int fib(int n) {
        return fibCount(n);
    }
};
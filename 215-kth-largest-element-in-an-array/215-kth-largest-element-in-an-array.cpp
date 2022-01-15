class Solution {
public:
    
    int partition(vector<int> &mas, int l, int r) {
        if (l != r)
            std::swap(mas[l + rand() % (r - l)], mas[r]);
        int x = mas[r];
        int i = l - 1;
        
        for (int j = l; j <= r; j++) {
            if (mas[j] <= x)
                std::swap(mas[++i], mas[j]);
        }
      return i;
    }
    int nth(vector<int> mas, int n) {
        int l = 0, r = mas.size() - 1;
        for(;;) {
            int pos = partition(mas,l,r);
            if (pos < n)
                l = pos + 1;
            else if (pos > n)
                r = pos - 1;
            else return mas[n];
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        return nth(nums, nums.size() - k);
        
    }
    
private:
    std::priority_queue<int> maxHeap;
};

// Constraints

/*
1 <= k <= nums.length <= X
-1e4 <= nums[i] <= 1e4
*/


// O(f(nlogn) + g(k))
// O(f(n) + g(K * logn))
class Solution {
public:
    
    int partition(vector<int> &mas, int left, int right) {
        if (left != right)
            std::swap(mas[left + rand() % (right - left)], mas[right]);
        
        int x = mas[right]; // x = 4
        int i = left - 1; // i = -1
        
        for (int j = left; j <= right; j++) {
            if (mas[j] <= x)
                std::swap(mas[++i], mas[j]);
        }
        return i;
    }
    
    int nth(vector<int> mas, int n) {
        int l = 0, r = mas.size() - 1;
        while (true) {
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
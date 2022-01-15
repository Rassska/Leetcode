class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->K = k;
        
        for (auto& num : nums) {
            minHeap.push(num);
        }
        
        while (minHeap.size() > K) {
            minHeap.pop();
        }
        
    }
    
    int add(int val) {
        minHeap.push(val);
        while (minHeap.size() > K) {
            minHeap.pop();
        }
        
        return minHeap.top();
        
    }
    
private:
    int K;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (auto& num : nums) {
            maxHeap.push(num);
        }
        k--;
        while (k--) {
            maxHeap.pop();
        }
        return maxHeap.top();
    }
    
private:
    std::priority_queue<int> maxHeap;
};
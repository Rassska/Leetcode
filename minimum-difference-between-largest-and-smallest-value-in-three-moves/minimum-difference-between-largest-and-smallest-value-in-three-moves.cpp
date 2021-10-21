class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() < 5) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        
        // std::priority_queue<int> maxHeap(nums.begin(), nums.end());
        // std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(nums.begin(), nums.end());
        
        
        int ans = std::numeric_limits<int>::max();
        
        for (int i = 0; i < 4; i++) {
            ans = std::min(ans, nums[nums.size() - 4 + i] - nums[i]);
        }
        return ans;
        
        
    }
};
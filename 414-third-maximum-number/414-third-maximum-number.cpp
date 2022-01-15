class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        int k = 2;
        
        for (auto& num : nums) {
            st.insert(num);
        }
        
        for (auto& num : st) {
            maxHeap.push(num);
        }
        if (k + 1 > st.size()) {
            return maxHeap.top();
        }
        
        while (k--) {
            maxHeap.pop();
            
        }
        return maxHeap.top();
    }
    
private:
    std::priority_queue<int> maxHeap;
    std::set<int> st;
};
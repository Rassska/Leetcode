
class helper {
public:
    bool operator()(std::string& s1, std::string& s2) {
        if (s1.size() == s2.size()) {
            return s2 < s1;
        }
        return s2.size() < s1.size();
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        for (auto& num : nums) {
            maxHeap.push(num);
        }
        k = nums.size() - k;
        while (k--) {
            maxHeap.pop();
        }
        return maxHeap.top();
    }
    
private:
    std::priority_queue<std::string, std::vector<std::string>, helper> maxHeap;
};
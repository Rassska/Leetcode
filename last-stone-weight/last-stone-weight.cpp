class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        for (auto& currStone : stones) {
            maxHeap.push(currStone);
        }
        while (maxHeap.size() > 1) {
            int firstMax = maxHeap.top(); maxHeap.pop();
            int secondMax = maxHeap.top(); maxHeap.pop();
            
            if (firstMax != secondMax) {
                maxHeap.push(abs(firstMax - secondMax));
            }
        }
        return maxHeap.size() * maxHeap.top();
    }
    
private:
    std::priority_queue<int> maxHeap;
};
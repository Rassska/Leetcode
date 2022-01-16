/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ansHead = nullptr;
        ListNode* ansTail = ansHead;
        
        for (std::size_t i = 0; i < lists.size(); i++) {
            for (auto it = lists[i]; it != nullptr;) {
                minHeap.push(it->val);
                it = it->next;
            }
        }
        
        if (minHeap.size() > 0) {
            ansHead = new ListNode(minHeap.top());
            ansTail = ansHead;
            minHeap.pop();
        }
        
        while (minHeap.size() > 0) {
            ansTail->next = new ListNode(minHeap.top());
            ansTail = ansTail->next;
            minHeap.pop();
        }
        
        return ansHead;
        
        
    }
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};
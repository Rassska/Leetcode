/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    const int hashTableSize = 1e3;
    
    bool hasCycle(ListNode *head) {
        
        if (head == nullptr)
            return false;
         
        ListNode* slow = head; // iterations = 1
        ListNode* fast = head->next; // iterations = 2  1 -> 2 -> 3 -> 4
        
        while(slow != nullptr && fast != nullptr) {
            if (slow == fast) {
                return true;
            }
            slow = slow->next;
            
            if (fast->next != nullptr) {
                fast = fast->next;
                fast = fast->next;
            } else {
                fast = nullptr;
            }
        }
        
        return false;
        
        
    }
};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
        // 1) Claryfying the problem
            // 1.1) 1 <= list.size() <= 30
            // 1.2) 0 <= Node.val <= 100
            // 1.3) integerer numbers
            // 1.4) returning pointer to the head after removing n-th element
        
        // 2) Initial approaches
            // 2.1) making another pointer to that linked list, reversing, removing n-th element
            // 2.2) making two pointers, first is iterating n times, till first -> next != nullptr, we move the second pointer.
            // 2.2.2) and changing the second -> next = second -> next -> next;
        
        // 3) Writing the solution
        
            ListNode* first = head;
            ListNode* second = head;
        
        while(n--) {
            first = first -> next;
        } 
        
        if (first == nullptr) return head -> next;
        while (first -> next != nullptr) {
            first = first -> next;
            second = second -> next;
        }
        
        second -> next = second -> next -> next;
        
        return head;
        
        // 4) Debugging 
            // 4.1) head = [1,2,3,4,5], n = 2  => first -> val = 3, second -> val = 3;
            // 4.2) head = [1], n = 1 => 
        
        
        
    }
};
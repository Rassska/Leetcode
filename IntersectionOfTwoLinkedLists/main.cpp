/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::vector <int> listInitPosition;
        ListNode* temp = headB;
        ListNode* ans = nullptr;
    
        while(temp != nullptr) {
            listInitPosition.push_back(temp->val);
            temp = temp->next;
        }
        
        temp = headA;
        
        while(temp != nullptr) {
            temp->val *= -1;
            temp = temp->next;
        }
        temp = headB;
        for (int i = 0; i < listInitPosition.size(); i++) {
            if (listInitPosition[i] == temp->val * -1) {
                ans = temp;
                break;
            }
            temp = temp->next;
        }
        
        temp = headA;
        
        while(temp != nullptr) {
            temp->val *= -1;
            temp = temp->next;
        }
        
        return ans;
        
        
        
    }
};

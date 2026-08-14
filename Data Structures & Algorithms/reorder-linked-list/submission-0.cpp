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
    void reorderList(ListNode* head) {
        ListNode* slow=head ;
        ListNode* fast=head ;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow=slow->next;
        }
        ListNode* h2 = slow->next;
        slow ->next = NULL;

        ListNode* curr = h2;
        ListNode* next = NULL; 
        ListNode* prev = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* temp1 = head;
        ListNode* next1 = NULL;
        while(prev != NULL){
            next1 = prev -> next;
            prev -> next = temp1 -> next;
            temp1 ->next = prev;
            temp1 = prev->next;
            prev = next1;
        }
    }
};

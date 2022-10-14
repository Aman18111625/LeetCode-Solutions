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
  ListNode* middleNode(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast and fast->next)
        {
          slow=slow->next;
          fast=fast->next->next;    
        } 
        return slow;
    }
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return head;
        if(!head->next) return NULL;
        if(!head->next->next)
        {
            head->next=NULL;
            return head;
        }
        ListNode* midNode=middleNode(head);
        deleteNode(midNode);
        return head;
    }
};
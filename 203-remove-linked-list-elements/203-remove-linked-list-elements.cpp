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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode *newHead=head;
        while(newHead->next)
        {
          if(newHead->next->val==val)
          {
            newHead->next=newHead->next->next;
          }
            else
            {
             newHead=newHead->next;
            }
        }
        if(head->val==val) head=head->next;
        return head;
    }
};
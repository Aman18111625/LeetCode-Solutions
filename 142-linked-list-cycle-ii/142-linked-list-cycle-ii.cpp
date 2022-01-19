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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        ListNode* slow=head,*fast=head;
        bool found=false;
        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) 
            {
                found=true;
                break;
            }
        }
        if(!found) return NULL;
        if(slow==head)
        {
            while(fast->next!=slow) fast=fast->next;
        }else if(slow==fast)
        {
            slow=head;
            while(fast->next!=slow->next) 
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
        return fast->next;
    }
};
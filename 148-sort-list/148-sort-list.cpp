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
  ListNode * midNode(ListNode *head)
{  
    ListNode *slow=head,*fast=head;
    while(fast->next &&  fast->next->next)
    {
         fast=fast->next->next;
         slow=slow->next;
    }
    return slow;
}

ListNode * mergeTwoSLL(ListNode *l1,ListNode *l2)
{
    if(!l1) return l2;
    if(!l2) return l1;
    ListNode *ptr1=l1;
    ListNode *ptr2=l2;
    ListNode *dummy=new ListNode(-1);
    ListNode *temp=dummy;
    while(ptr1 && ptr2)
    {
     if(ptr1->val<=ptr2->val)
     {
        temp->next=ptr1;   
        ptr1=ptr1->next;
     }
     else
     {
        temp->next=ptr2;
        ptr2=ptr2->next;
     }
     temp=temp->next;   
    }
    temp->next=(ptr1) ? ptr1 : ptr2;
    return dummy->next;
}
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *mid=midNode(head);
        ListNode *newHead=mid->next;
        mid->next=NULL;
        ListNode *l1=sortList(head);
        ListNode *l2=sortList(newHead);
        return mergeTwoSLL(l1,l2);
    }
};
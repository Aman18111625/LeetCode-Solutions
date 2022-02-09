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
  /*
  //Recursive Code
  //TC:=>O(N)
  //SC:=>O(N)(stack-space)
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* curr=head;
        head=head->next;
        curr->next=head->next;
        head->next=curr;
        head->next->next=swapPairs(head->next->next);
      return head;
    }*/
  //Iterative
  ListNode* swapPairs(ListNode* head){
      if(!head or !head->next) return head;
      ListNode* dummy=new ListNode(-1);
      dummy->next=head;
      ListNode* prev=dummy;
    while(prev->next && prev->next->next)
    {
       ListNode* current=prev->next;
       ListNode* forward=current->next;
       ListNode* temp=forward->next;
        prev->next=forward;
        forward->next=current;
        current->next=temp;
       prev=current;
    }
    return dummy->next;
  }
};
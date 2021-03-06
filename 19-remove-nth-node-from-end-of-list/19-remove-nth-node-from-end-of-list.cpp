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
  //Brute-Force Approach
  //TC:=>O(2N)
  //SC:=>O(1)
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if(!head) return head;
    //     if(n==1 && !head->next) return NULL;
    //     int len=0;
    //     ListNode* curr=head;
    //     while(curr){
    //       len++;
    //       curr=curr->next;
    //     }
    //     if(len==n) return head->next;
    //     curr=head;
    //     for(int i=0;i<(len-n-1);i++) curr=curr->next;
    //     curr->next=curr->next->next;
    //     return head;
    // }
  
  //Efficient Approach -> Using Two Pointer
  //TC:=>O(N)
  //SC:=>O(1)
   ListNode* removeNthFromEnd(ListNode* head, int n){
       ListNode * start = new ListNode();
        start -> next = head;
       ListNode* fast=start,*slow=start;
       for(int i=1;i<=n;i++) fast=fast->next;
       while(fast->next){
         slow=slow->next;
         fast=fast->next;
       }
       slow->next=slow->next->next;
       return start->next;
   }
};


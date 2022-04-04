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
  /*Approach-1
   int length(ListNode* head){
     if(!head) return 0;
     if(!head->next) return 1;
     int len=0;
     ListNode* curr=head;
     while(curr){
       len++;
       curr=curr->next;
     }
     return len;
   }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head or !head->next) return head;
        int i=0;
        ListNode* curr=head;
        while(i<k-1 && curr){
          curr=curr->next;
          i++;
        }
        i=0;
        int n=length(head);
        ListNode* curr2=head;
        while(i<n-k){
          curr2=curr2->next;
          i++;
        }
        int val=curr->val;
        curr->val=curr2->val;
        curr2->val=val;
        return head;
    }*/
   public:
   ListNode* swapNodes(ListNode* head,int k){
        ListNode *ptr1 = head, *ptr2 = head, *kth = NULL;
        while (--k)
            ptr1 = ptr1->next;
        
        kth = ptr1;
        ptr1 = ptr1->next;
        while (ptr1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        swap(ptr2->val, kth->val);
        return head;
   }
};
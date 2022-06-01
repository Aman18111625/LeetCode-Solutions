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
  //TC:=>O(N*K)
  //SC:=>O(1)
  //moving last k node to first of the Linked-List
  // ListNode* rotateRight(ListNode* head,int k) {
  //   if(!head || !head->next) return head;
  //   for(int i=0;i<k;i++) {
  //       ListNode* temp = head;
  //       while(temp->next->next) temp = temp->next;
  //       ListNode* end = temp->next;
  //       temp->next = NULL;
  //       end->next = head;
  //       head = end;
  //   }
  //   return head;
  //  }
  
    //Optimal Approach
    //TC:=>O(N)
    //SC:=>O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int n=1;
        ListNode *curr=head;
        while(curr->next && ++n) curr=curr->next;   
        curr->next=head;
        k=k%n;
        k=(n-k);
        while(k--) curr=curr->next;
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};
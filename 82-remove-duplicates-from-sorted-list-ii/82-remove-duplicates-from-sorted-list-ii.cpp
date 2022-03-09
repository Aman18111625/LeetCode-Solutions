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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp=dummy;
        temp->next=head;
        ListNode* curr=head->next;
        while(curr){
          bool flag=false;
          while(curr && temp->next->val==curr->val){
            flag=true;
            curr=curr->next;
          }
          if(flag) temp->next=curr;
          else temp=temp->next;
          if(curr) curr=curr->next;
        }
      return dummy->next;
    } 
};
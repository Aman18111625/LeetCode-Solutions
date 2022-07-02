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
  //Brute-Force Approach
  //TC:=>O(N)
  //SC:=>O(N)
  // node* detectCycle(node* head) {
  //   unordered_set<node*> st;
  //   while(head) {
  //       if(st.find(head) != st.end()) return head;
  //       st.insert(head);
  //       head = head->next;
  //   }
  //   return NULL;
  // }
  
  //Optimal Approach
  //TC:=>O(N)
  //SC:=>O(1)
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        ListNode* slow=head,*fast=head;
        bool found=false;
        //find the collision point
        while(slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {
                found=true;
                break;
            }
        }
        if(!found) return NULL;//there's no loop in the LL.
        if(slow==head){
          while(fast->next!=slow) fast=fast->next;
        }else if(slow==fast){
            slow=head;
            while(fast->next!=slow->next) {
                slow=slow->next;
                fast=fast->next;
            }
        }
        return fast->next;
    }
};
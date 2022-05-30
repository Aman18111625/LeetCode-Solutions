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
  //Brute Force Approach->
  //Store all the values in the array and reverse that arary and create new LL
  //TC:=>O(N)
  //SC:=>O(N+N)
    ListNode* reverseList(ListNode* head) {
         if(!head || !head->next) return head;
         ListNode* curr=head;
         vector<int>ans;
         while(curr){
           ans.push_back(curr->val);
           curr=curr->next;
         }
         reverse(ans.begin(),ans.end());
         ListNode* newhead=new ListNode(ans[0]);
         ListNode* temp=newhead;
         int i=1,n=ans.size();
         while(i<n){
           temp->next=new ListNode(ans[i]);
           temp=temp->next;
           i++;
         }
        return newhead;
    }
};
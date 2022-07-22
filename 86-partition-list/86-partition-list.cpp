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
    ListNode* partition(ListNode* head, int x) {
        vector<int>less,equal;
        ListNode* curr=head;
        while(curr){
          if(curr->val<x){
            less.push_back(curr->val);
          }else if(curr->val>=x){
            equal.push_back(curr->val);
          }
          curr=curr->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp=dummy;
        for(auto num : less){
          temp->next= new ListNode(num);
          temp=temp->next;
        }
        for(auto num : equal){
          temp->next= new ListNode(num);
          temp=temp->next;
        }
        return dummy->next;
    }
};
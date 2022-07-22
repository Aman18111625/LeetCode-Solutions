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
    //Brute-Force Approach:->just store lesser and equal or greater value in vector and create a new LinkedList
    //TC:=>O(N)
    //SC:=>O(N)
    // ListNode* partition(ListNode* head, int x) {
    //     vector<int>less,equal;
    //     ListNode* curr=head;
    //     while(curr){
    //       if(curr->val<x){
    //         less.push_back(curr->val);
    //       }else if(curr->val>=x){
    //         equal.push_back(curr->val);
    //       }
    //       curr=curr->next;
    //     }
    //     ListNode* dummy = new ListNode(-1);
    //     ListNode* temp=dummy;
    //     for(auto num : less){
    //       temp->next= new ListNode(num);
    //       temp=temp->next;
    //     }
    //     for(auto num : equal){
    //       temp->next= new ListNode(num);
    //       temp=temp->next;
    //     }
    //     return dummy->next;
    // }
  
    //Optimized Approach:->by using implace algorithm
    //TC:=>O(N)
    //SC:=>O(1)
    ListNode* partition(ListNode* head,int x){
        ListNode *lesser = new ListNode(-1), *greater = new ListNode(-1);
        ListNode *lesser_head = lesser, *greater_head = greater;
      while(head){
         if(head -> val < x) 
            lesser -> next = head, lesser = lesser -> next;
         else 
            greater -> next = head, greater = greater -> next;
         head = head -> next; 
      }
     greater -> next = NULL;
     lesser -> next = greater_head -> next;
     return lesser_head -> next;
    }
};
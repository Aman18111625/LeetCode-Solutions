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
    ListNode* reverseBetween(ListNode* head, int i, int j) {
        //base case
         if(!head || i==j) return head;
        ListNode* prev=NULL,*curr=head;
        for(int l=0;curr && l<i-1;l++)
        {
          prev=curr;
          curr=curr->next;
        }
        ListNode* left=prev;//store 0 to i-1 list
        ListNode* newend=curr;
        int total=j-i+1;//total number of elements to be reversed
        ListNode* nex=curr->next;
      //reversed sublist from i to j 
        for(int l=0; curr && l<total;l++)
        {
          curr->next=prev;
          prev=curr;
          curr=nex;
          if(nex) nex=nex->next;
        }
        if(left) left->next=prev; //because might be i=0
        else head=prev;
        newend->next=curr;//curr will be updated toh the r+1th element so joining newend to that
      return head;
    }
};
 

 
 
 
 
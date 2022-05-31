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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
         if(!head or !head->next or  k==1) return head;
         ListNode *dummy=new ListNode(0);
          dummy->next=head;
         ListNode *cur=dummy,*pre=dummy,*nex=dummy;
         int count=0;
        //step-1 count the length of linked list
        while(cur->next) {
         cur=cur->next;
         count++;
        }
        //step-2 reverse in k-size of group .Here we don't have to reverse those groups whose size is less than k.
        while(count>=k){
            cur=pre->next;
            nex=cur->next;
            for(int i=1;i<k;i++){
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                 nex=cur->next;
            }
            pre=cur;
            count-=k;
        }
        return dummy->next;//now head of the modified linkedlist 
    }
};
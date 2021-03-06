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
  //Brute Force Approach
  //TC:=>O(N+M)
  //SC:=>O(N+M)
  //we're create new Linked List 
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//            if(!list1 && !list2) return NULL;
//            if(!list1) return list2;
//            if(!list2) return list1;
//            ListNode* dummy = new ListNode();
//            ListNode* temp=dummy;
//            while(list1 && list2){
//               if(list1->val<=list2->val){
//                 temp->next=new ListNode(list1->val);
//                 list1=list1->next;
//               }else {
//                 temp->next=new ListNode(list2->val);
//                 list2=list2->next;
//               }
//              temp=temp->next;
//            }
           
//           while(list1){
//             temp->next=new ListNode(list1->val);
//             temp=temp->next;
//             list1=list1->next;
//           }
         
//          while(list2){
//            temp->next= new ListNode(list2->val);
//            temp=temp->next;
//            list2=list2->next;
//          }
//         return dummy->next;
//     }
  
  //Efficient Approach-> Without Using Extra Space
  //TC:=>O(M+N)
  //SC:=>O(1)                                   
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
       if(!list1 && !list2) return NULL;
       if(!list2) return list1;
       if(!list1) return list2;
       if(list1->val>list2->val) swap(list1,list2);
       ListNode* res=list1;
       while(list1 && list2){
         ListNode* temp=NULL;
         while(list1 && list1->val<=list2->val){
           temp=list1;
           list1=list1->next;
         }
         temp->next=list2;
         swap(list1,list2);
       }
      return res;
  }
};



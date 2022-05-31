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
  //Brute Force Approach
  //TC:=>O(M*N)
  //SC:=>O(1)
  //Approach-> As we know intersection means common attribute. To find common attribute in 2 Linked-List, Here we'll choose 2nd LL and check for it's node present in 1st LL or not.If present then we got our answer otherwise repeat this steps until head2!=NULL. 
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //    while(headB){
    //      ListNode* temp=headA;
    //      while(temp){
    //        if(temp==headB) return temp;
    //        temp=temp->next;
    //      }
    //      headB=headB->next;
    //    }   
    //   return NULL;
    // }
  
    //Better Approach->Using Hashing->store node address of list1 in set then search of node of list2 .If find then we got our answer else return NULL at the end,
    //TC:=>O(M+N)
    //SC:=>O(M)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){ 
      unordered_set<ListNode*>st;
      while(headA){
        st.insert(headA);
        headA=headA->next;
      } 
      
      while(headB){
        if(st.count(headB)) return headB;
        headB=headB->next;
      }
      return NULL;
    }
};
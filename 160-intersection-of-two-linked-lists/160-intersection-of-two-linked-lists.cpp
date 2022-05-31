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
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){ 
//       unordered_set<ListNode*>st;
//       while(headA){
//         st.insert(headA);
//         headA=headA->next;
//       } 
      
//       while(headB){
//         if(st.count(headB)) return headB;
//         headB=headB->next;
//       }
//       return NULL;
//     }
  
//Optimal Approach ->Using Difference of Length.
//Find length of both the lists.
// Find the positive difference of these lengths.
// Move the dummy pointer of the larger list by difference achieved. This makes our search length reduced to the smaller list length.
// Move both pointers, each pointing two lists, ahead simultaneously if both do not collide.
  //TC:=>O(N+M)
  //SC:=>O(1)
    int getDifference(ListNode* headA,ListNode* headB){
      int len1=0,len2=0;
      while(headA){
        len1++;
        headA=headA->next;
      }
      while(headB){
        len2++;
        headB=headB->next;
      }
      return len1-len2;
    }
   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
          int diff=getDifference(headA,headB);
          if(diff<0) 
            while(diff++!=0) headB=headB->next;
          else
            while(diff--!=0) headA=headA->next;
          while(headA && headB){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
          }
         return NULL;
   }
  
};
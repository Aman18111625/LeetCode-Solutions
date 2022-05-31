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
   //Brute-Force Approach->Using Extra Space
   //TC:=>O(N)
  //SC:=>O(N)
  //Simply store values in the array and check if arr[i] is equal to arr[n-i-1] or not .If not then it's not palindrome else it's palindrome
    // bool isPalindrome(ListNode* head) {
    //     vector<int> arr;
    //     while(head) {
    //      arr.push_back(head->val);
    //      head = head->next;
    //    }
    //    for(int i=0;i<arr.size()/2;i++) 
    //      if(arr[i] != arr[arr.size()-i-1]) return false;
    //    return true;
    // }
  
  //Optimized Approach
  //TC:=>O(N)
  //SC:=>O(1)
  //step1 ->find middle node
  //step2 -> now reverse the whole list after  middle node
  //step3 -> now compare values of node before middle node and after middle node.
  
  //finding mid node
    ListNode* findMid(ListNode* head){
        ListNode* slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }
        return slow;
    }
    
  //reversing the list
    ListNode* reverseList(ListNode* head){
        ListNode* curr=head;
        ListNode* temp=NULL;
        ListNode* prev=NULL;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    
    bool compareList(ListNode* head1, ListNode* head2){
        while(head1 && head2){
            if(head1->val != head2->val) return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
       if(!head or !head->next) return true;
        ListNode* curr=head;
        ListNode* mid=findMid(curr);
        ListNode* head1=reverseList(mid);
        return compareList(head,head1);
    }
};
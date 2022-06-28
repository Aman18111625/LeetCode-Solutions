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
  //Approach-1 : simple store in vector and apply rule according to question
  //TC:=>O(N)
  //SC:=>O(N)
//     int pairSum(ListNode* head) {
//        vector<int>nums;
//        int len=0;
//        ListNode* curr=head;
//        while(curr){
//          len++;
//          nums.push_back(curr->val);
//          curr=curr->next;
//        }
       
//        int maxi=0;
//        for(int i=0;i<=(len/2)-1;i++){
//          maxi=max(maxi,nums[i]+nums[len-i-1]);
//        }
//        return maxi;
//     }
  
  //Approach-2 : Simply reverse from mid and apply rule according to question
  //TC:=>O(N)
  //SC:=>O(1)
  ListNode* Reverse(ListNode* cur, ListNode* prev = nullptr) {
    while (cur) {
        swap(cur->next, prev);
        swap(prev? prev->next : prev, cur);
    }
    return prev;
  }    
  int pairSum(ListNode* head) {
    int res = 0;
    //find mid of Linked-List
    ListNode* slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    //reverse from mid
    slow = Reverse(slow);
    while(slow) {
        res = max(res, slow->val + head->val);
        slow = slow->next;
        head = head->next;
    }
    return res;
}
};
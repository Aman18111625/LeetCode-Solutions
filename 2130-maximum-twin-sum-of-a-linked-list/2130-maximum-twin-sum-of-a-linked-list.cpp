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
    int pairSum(ListNode* head) {
       vector<int>nums;
       int len=0;
       ListNode* curr=head;
       while(curr){
         len++;
         nums.push_back(curr->val);
         curr=curr->next;
       }
       
       int maxi=0;
       for(int i=0;i<=(len/2)-1;i++){
         maxi=max(maxi,nums[i]+nums[len-i-1]);
       }
       return maxi;
    }
};
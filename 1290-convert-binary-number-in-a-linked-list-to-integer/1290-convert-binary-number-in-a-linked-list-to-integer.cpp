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
    int getDecimalValue(ListNode* head) {
     if(!head or !head->next) return head->val;
        ListNode* curr=head;
         string temp="";
        while(curr)
        {
            temp+=(to_string(curr->val));
            curr=curr->next;
        }
        int ans=0;
        for(int i=size(temp)-1,j=0;i>=0;i--,j++)
        {
            int num=temp[i]-'0';
            ans+=(1<<j)*num;
        }
        return ans;
    }
};
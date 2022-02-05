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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>ans;
         int n=lists.size();
         if(n==0) return NULL;
         if(n==1) return lists[0];
         for(int i=0;i<n;i++)
         {
           ListNode* temp=lists[i];
           while(temp)
           {
             ans.push_back(temp->val);
             temp=temp->next;
           }
         }
      sort(ans.begin(),ans.end());
      ListNode* dummy=new ListNode(-1);
      ListNode* temp=dummy;
       for(auto &it: ans)
       {
         temp->next = new ListNode(it);
         temp=temp->next;
       }
      return dummy->next;
    }
};

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
  stack<int>st;
  void helper(ListNode* root)
  {
    if(!root) return ;
    helper(root->next);
    while(!st.empty() && st.top()<=root->val) st.pop();
    int val=root->val;
    root->val=st.empty()?0:st.top();
    st.push(val);
  }
public:
    vector<int> nextLargerNodes(ListNode* head) {
      vector<int>ans;
      if(!head ) return ans;
      if(!head->next) return {0};
      helper(head);
      ListNode* curr=head;
      while(curr) 
      {
        ans.push_back(curr->val);
        curr=curr->next;
      }
       return ans;
    }
};
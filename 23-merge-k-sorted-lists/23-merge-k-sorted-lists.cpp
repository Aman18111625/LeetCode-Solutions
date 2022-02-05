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

  /*
  //Time-Complextity:=>O(N*k)+O(Nklogn(NK));
  //Space-Complexity:=>O(N*k)
  //store all the value in the vector then sort it and create a new List
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
    }*/
  //Approach-2 
  //Time-Complexity:O(NlogN)
  //Space-Complexity:O(N)
  //initally we have pushed all the head of the k lists into pq then take top of pq and move to the next of top && if it's not null then push into pq and again do the same process again and again untill pq is not empty
  struct compare{
        bool operator()(ListNode *a, ListNode *b){
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        for(auto li : lists){
            if(li) pq.push(li);
        }
        if(pq.empty()) return NULL;
        ListNode *dummy = new ListNode(0), *temp = dummy;
        while(pq.size()){
            auto curr = pq.top(); pq.pop();
            temp->next = curr;
            temp = temp->next;
            curr = curr->next;
            if(curr) pq.push(curr);
        }
        return dummy->next;
    }
};



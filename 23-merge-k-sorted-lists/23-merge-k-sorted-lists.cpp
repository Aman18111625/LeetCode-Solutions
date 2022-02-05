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
   struct node{
       ListNode *curr;
        int idx;
        node(ListNode *a,int b)
        {
           curr=a;
            idx=b;
        }
    };
    struct cmp{
      bool operator()(node a,node b)
      {
        return a.curr->val > b.curr->val; 
      }
    };
public:
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
  //Time-Complexity:O(N)
  //Space-Complexity:O(NK)
  //initally we have pushed all the head of the k lists into pq then take top of pq and move to the next of top && if it's not null then push into pq and again do the same process again and again untill pq is not empty
  ListNode* mergeKLists(vector<ListNode*>& lists){
    int n=lists.size();
    if(n==0) return NULL;
    if(n==1) return lists[0];
    ListNode* head=NULL,*tail=NULL;
    priority_queue<node,vector<node>,cmp>heap;
    vector<ListNode*>ptr(n);
    for(int i=0;i<n;i++)
    {
      ptr[i]=lists[i];
      if(ptr[i]) heap.push(node(ptr[i],i));
    }
    if(heap.empty()) return NULL;
    head=tail=heap.top().curr;
    int idx=heap.top().idx;
    heap.pop();
    ptr[idx]=ptr[idx]->next;
    if(ptr[idx]) heap.push(node(ptr[idx],idx));
    while(!heap.empty())
    {
      ListNode* temp=heap.top().curr;
      idx=heap.top().idx;
      heap.pop();
      tail->next=temp;
      tail=tail->next;
      ptr[idx]=ptr[idx]->next;
      if(ptr[idx]) heap.push(node(ptr[idx],idx));
    }
    return head;
  }
};



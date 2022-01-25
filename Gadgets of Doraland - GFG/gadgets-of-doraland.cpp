// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    struct cmp{
       bool operator()(pair<int,int>&a,pair<int,int>&b){
           if(a.first==b.first) return b.second>a.second;
           return a.first<b.first;
       }  
    };
    
    vector<int> TopK(vector<int>& array, int k)
    {
        // code here
        map<int,int>mpp;
        for(auto &it: array) mpp[it]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        vector<int>ans;
        for(auto &it : mpp)
          pq.push({it.second,it.first});
         while(k--)
         {
             ans.push_back(pq.top().second);
             pq.pop();
         }
         return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // } Driver Code Ends
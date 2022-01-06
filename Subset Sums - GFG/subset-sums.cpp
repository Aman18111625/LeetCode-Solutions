// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
  void helper(vector<int>&arr,vector<int>&ans,int idx,int n,int curr=0){
      if(idx>n){
        ans.push_back(curr);
        return ;
      } 
      //we have two option -> 1.pick 2.not pick
      //op1
      helper(arr,ans,idx+1,n,curr);
      //op2
      helper(arr,ans,idx+1,n,curr+arr[idx]);
  }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        helper(arr,ans,0,N-1,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
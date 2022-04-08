// { Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        // code here
        vector<int>ans;
        unordered_map<int,int>mpp;
        stack<int>st;
        for(int i=0;i<n;i++) mpp[arr[i]]++;
        for(int i=n-1;i>=0;i--){
            if(st.empty()) st.push(arr[i]);
            while(!st.empty() && mpp[arr[i]]>=mpp[st.top()]) st.pop();
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    }
	return 1;
}
  // } Driver Code Ends
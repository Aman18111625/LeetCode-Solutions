//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        //Code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        // int ans=1;
        // for(int i=0;i<n;i++){
        //     int cnt=1;
        //     for(int j=i+1;j<n;j++){
        //         if(arr[j]-arr[i]<=k) cnt++;
        //         else break;
        //     }
        //     ans=max(ans,cnt);
        // }
        // return n-ans;
        int first=0,last=0;
        for(int i=0;i<n;i++){
            while(arr[i]-arr[first]>k) first++;
            last=max(last,i-first+1);
        }
        return n-last;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends
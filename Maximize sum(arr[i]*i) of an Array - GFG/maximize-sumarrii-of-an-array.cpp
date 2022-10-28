//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    const int mod=1e9+7;
    public:
    int Maximize(int a[],int n)
    {
        // Complete the function
        sort(a,a+n);
        long sum=0;
        for(int i=0;i<n;i++){
            long curr=a[i],index=i;
            sum=sum%mod+(curr*index)%mod;
        }
        return (int)sum%mod; 
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends
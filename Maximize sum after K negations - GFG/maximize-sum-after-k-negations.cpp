//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        int sum=0,mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(a[i]<0 && k>0) {
                a[i]*=-1;
                k--;
            }
            sum+=a[i];
            mini=min((long long int)mini,a[i]);
        }
        if(k){
            if(k&1){
                mini*=-2;
                sum+=mini;
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool helper(int a[],int n,vector<int>&groups,int target){
        if(n<0) return true;
        for(int i=0;i<groups.size();i++){
            if(groups[i]+a[n]>target) continue;
            groups[i]+=a[n];
            if(helper(a,n-1,groups,target)) return true;
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k){
         //Your code here
         if(n<k or k==0) return false;
         int sum=0;
         for(int i=0;i<n;i++) sum+=a[i];
         if(sum%k) return false;
         vector<int>groups(k,0);
         sort(a,a+n);
         if(a[n-1]>sum) return false;
         return helper(a,n-1,groups,sum/k);
    }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends
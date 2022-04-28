// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    long long int killinSpree(long long int n)
    {
        // Code Here
        /*
        long long int cnt=0;
        int i=1;
        while(n){
            if(n>=i*i){
                n-=i*i;
                cnt++;
            }else break;
            i++;
        }
        return cnt;
        */
        long long int low=1,high=1e6;
        long long int mid,sum=0,ans=0;
        while(low<=high){
            mid=(low)+(high-low)/2;
            sum=mid*1LL*(mid+1)*(2*mid+1);
            sum/=6;
            if(sum<=n){
                low=mid+1;
                ans=mid;
            }else{
                high=mid-1;
            }
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
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}
  // } Driver Code Ends
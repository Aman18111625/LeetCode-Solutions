// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    int isPossible(int arr[],int n,int d,int bound)
    {
        int day=1,curr_cap=0;
        for(int i=0;i<n;i++)
        {
            curr_cap+=arr[i];
            if(curr_cap>bound)
            {
                day++;
                curr_cap=arr[i];
                if(day>d) return false;
            }
        }
        return day<=d;
    }
  public:
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int low=0,high=0,ans=INT_MAX;
        for(int i=0;i<N;i++)
        {
            low=max(low,arr[i]);
            high+=arr[i];
        }
        while(low<=high)
        {
         int mid=(low+high)>>1;
         if(isPossible(arr,N,D,mid))
         {
             high=mid-1;
             ans=mid;
         }else{
             low=mid+1;
         }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends
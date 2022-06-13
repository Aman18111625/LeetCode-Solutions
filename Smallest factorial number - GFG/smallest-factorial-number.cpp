// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    int getCount(int n){
        int cnt=0;
        while(n){
            cnt+=(n/5);
            n/=5;
        }
        return cnt;
    }
    public:
        int findNum(int n)
        {
        //complete the function here
          int low=1,high=5*n,mid;
          while(low<=high){
             mid=(low+high)/2;
            if(getCount(mid)==n && mid%5==0) return mid;
            else if(getCount(mid)<n) low=mid+1;
            else high=mid-1;
          } 
          while(mid%5) mid++;
          return mid;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends
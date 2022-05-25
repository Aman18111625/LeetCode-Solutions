// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int a
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(arr[i][0]!=arr[i+1][0]) continue;
            else{
                ans=max(ans,__gcd(max(arr[i][1],arr[i+1][1]),min(arr[i][1],arr[i+1][1])));
                i++;
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
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
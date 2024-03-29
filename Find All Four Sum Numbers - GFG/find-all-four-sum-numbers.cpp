//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
   vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());//sorting will help us to skip duplicates
        int n=arr.size();
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int target=k-arr[i]-arr[j];
                int low=j+1,high=n-1;
                while(low<high){
                    int sum=arr[low]+arr[high];
                    if(sum<target) low++;
                    else if(sum>target) high--;
                    else {
                        vector<int>curr(4,0);
                        curr[0]=arr[i];
                        curr[1]=arr[j];
                        curr[2]=arr[low];
                        curr[3]=arr[high];
                        ans.push_back(curr);
                        //steps to avoid duplicants
                        while(low<high && arr[low]==curr[2]) ++low;
                        while(low<high && arr[low]==curr[3]) --high;
                    }
                }
            while(j+1<n && arr[j+1]==arr[j]) ++j;
            }
        while(i+1<n && arr[i+1]==arr[i]) ++i;
        }
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
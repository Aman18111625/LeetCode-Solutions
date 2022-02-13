// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
         vector<int> nums(n+1, 0);
        
        for(auto i = 0; i < n; i++){
            nums[arr[i]]++;
        }
        int a, b;
        for(auto i = 1; i <= n; i++){
            if(nums[i] == 0) a = i;
            if(nums[i] == 2) b = i;
        }
        arr[0] = b, arr[1] = a;
        return arr;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
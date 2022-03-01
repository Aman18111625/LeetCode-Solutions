// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
   double slope(pair<int, int> a, pair<int, int> b){
    if (b.first - a.first == 0)
        return 1510; // for infinite slope, it's just random value
    return (b.second - a.second) / (double)(b.first - a.first);
  }
  public:
    int mostBalloons(int N, pair<int, int> arr[]) {
        // Code here
        int ans=0;
        for(int i=0;i<N;i++){
         unordered_map<double,int>mpp;
         int dup=1;
         for(int j=i+1;j<N;j++){
             if(arr[i]==arr[j]){//in case of same pair then increment dup by 1
                 dup++;
             }else{
                 double s=slope(arr[i],arr[j]);//find slope of two points and store into hashmap
                 mpp[s]++;
             }
         }
        // ans=max(ans,dup);
        //count max number of points on a line when arr[i] is starting points and updating ans
         for(auto &it: mpp) ans=max(ans,it.second+dup);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends
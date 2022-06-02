// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    bool static comp(pair<int,int>&a,pair<int,int>&b){
        return b.second>a.second;
    }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i]={start[i],end[i]};
        }
         int res = 1;
         sort(arr.begin(),arr.end(),comp);
         int lastDoneAct = arr[0].second;
         for(int i=1;i<n;i++){
           if(arr[i].first >lastDoneAct){
            //i will be doing the activity
            res+=1;
            lastDoneAct = arr[i].second;
            }
         }
         return res;
     }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
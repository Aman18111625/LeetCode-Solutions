// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxEvents(int start[], int end[], int N) {
        // code here
        vector<pair<int,int>> A(N);
        for(int i=0; i<N; i++)
        {
            A[i].first = start[i];
            A[i].second = end[i];
        }
        sort(A.begin(),A.end());//sort according to end time
        unordered_set<int>st;
        //A[i].second->end day ,A[i].first->start day
        //we'll try to attend all the events at late as possible 
         for(int i=N-1;i>=0;i--)
         {
             //i can attend at last day
             if(st.count(A[i].second)==0)
             {
                 st.insert(A[i].second);
             }else{//search from end to start in which day it's possible to attend that events
                 int e=A[i].second;
                 while(e>=A[i].first)
                 {
                    if(st.count(e)==0){
                      st.insert(e);
                      break;
                    }
                     e--;
                 }
             }
         }
        return st.size();
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];

        Solution ob;
        cout << ob.maxEvents(start,end,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
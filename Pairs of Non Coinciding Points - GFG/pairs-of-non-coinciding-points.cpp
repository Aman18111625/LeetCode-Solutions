// { Driver Code Starts

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int numOfPairs(int X[], int Y[], int n) {
        // code here
        map<int,int>map1;
        int cnt1=0;//counting pairs having x coordinate as qual
        for(int i=0;i<n;i++){
            if(map1.find(X[i])!=map1.end()){
                cnt1+=map1[X[i]];
            }
            map1[X[i]]++;
        }
        
        map<int,int>map2;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(map2.find(Y[i])!=map2.end()){
                cnt2+=map2[Y[i]];
            }
            map2[Y[i]]++;
        }
        
        map<pair<int,int>,int>map3;
        int cnt3=0;
        for(int i=0;i<n;i++){
            if(map3.find({X[i],Y[i]})!=map3.end()){
                cnt3+=map3[{X[i],Y[i]}];
            }
            map3[{X[i],Y[i]}]++;
        }
        return cnt1+cnt2-2*cnt3;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
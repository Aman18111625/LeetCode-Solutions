// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool isValid(int x,int y,int n){
        if(x>=n or x<0 or y>=n or y<0) return 0;
        return 1;
    }
    // vector<vector<int>> formCoils(int n) {
    //     // code here
    //     n=4*n;
    //     vector<vector<int>>mat(n,vector<int>(n,-1));
    //     int cnt=1;
    //     //fill matrix
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             mat[i][j]=cnt++;
    //         }
    //     }
        
    //     int XI=n/2-1,YI=n/2;
    //     vector<int>ans1,ans2;
    //     vector<string>directions={"down","left","up","right"};
    //     int dir=0;
    //     ans1.push_back(mat[XI][YI]);
    //     int steps=2;
    //     int incSteps=0;
    //     while(mat[XI][YI]!=1){
    //         for(int i=0;i<steps;i++){
    //             if(mat[XI][YI]==1) break;
    //             if(directions[dir]=="down") XI++;
    //             else if(directions[dir]=="left") YI--;
    //             else if(directions[dir]=="up") XI--;
    //             else if(directions[dir]=="right") YI++;
    //             if(isValid(XI,YI,n)) ans1.push_back(mat[XI][YI]);
    //         }
    //             dir=(dir+1)%4;
    //             incSteps++;
    //             if((incSteps%2)==0) steps+=2;
    //         }
    //         for(auto it : ans1) ans2.push_back(n*n+1-it);
    //         mat.clear();
    //         mat.push_back(ans2);
    //         mat.push_back(ans1);
    //         return mat;
        
    // }
    vector<vector<int>> formCoils(int n){
        int m=8*n*n;//size of coil
        vector<int>c1(m);
        c1[0]=8*n*n+2*n;
        int curr=c1[0];
        int flag=1,steps=2;//flag tell us when we have to decrease or increase
        for(int ind=1;ind<m;){
            for(int i=0;i<steps;i++){
                curr=c1[ind++]=(curr-4*n*flag);
                if(ind>=m) break;
            }
            if(ind>=m) break;
            for(int i=0;i<steps;i++){
                curr=c1[ind++]=(curr+flag);
                if(ind>=m) break;
            }
            flag*=(-1);
            steps+=2;
        }
        vector<int>c2(m);
        for(int i=0;i<m;i++){
            c2[i]=16*n*n+1-c1[i];
        }
        vector<vector<int>>ans;
        ans.push_back(c1);
        ans.push_back(c2);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    public:
    vector<int>parent,size;
    DisjointSet(int v){
        parent.resize(v+1);
        size.resize(v+1,1);
        for(int i=0;i<=v;i++)
          parent[i] = i;
    }

    int findParent(int u){
        if(parent[u] == u)  return u;
        return parent[u] = findParent(parent[u]);
    }

    void Union(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv)    return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

};

class Solution {
    bool isValid(int i, int j, int n, int m){
      return i>=0 && i<n && j>=0 && j<m;
    }
   public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>>vis(n,vector<int> (m,0));
        vector<int> ans;
        int isLands=0;
        for(auto it: operators){
            int a = it[0];
            int b = it[1];
            if(!vis[a][b]){
                vis[a][b]=1;
                isLands++;
                int x[]={0,-1,0,1};
                int y[]={1,0,-1,0};
                for(int j=0;j<4;j++){
                    int newx=a+x[j];
                    int newy=b+y[j];
                    
                    if(isValid(newx,newy,n,m) && vis[newx][newy]){
                        int u=a*m+b;
                        int v=newx*m+newy;
                        if(ds.findParent(u)!=ds.findParent(v)){
                            ds.Union(u,v);
                            isLands--;
                        }
                    }
                }
            }
            ans.push_back(isLands);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
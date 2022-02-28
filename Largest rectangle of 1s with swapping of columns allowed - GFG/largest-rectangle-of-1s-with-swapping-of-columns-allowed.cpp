// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
    int getMaxArea(vector<int>& a,int n){
	    sort(a.begin(),a.end());
	    int ans = 0;
	    for(int i=0;i<n;i++){
	        ans = max(ans, a[i]*(n-i));
	    }
	    return ans;
	}
public:	
	// Returns area of the largest rectangle of 1's
	int maxArea(vector<bool> mat[], int r, int c) {
	    vector<vector<int>>aux (r,vector<int>(c,0));
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            aux[i][j] = (mat[i][j]==true ? 1 : 0);
	            if(i>0){
	                if(aux[i][j]) aux[i][j]+=aux[i-1][j];
	            }
	        }
	    }
	    int ans = 0;
	    for(auto& x:aux){
	        ans=max(ans,getMaxArea(x,c));
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c, x;
        cin >> r >> c;
        vector<bool> mat[r];
        for (int i = 0; i < r; i++) {
            mat[i].assign(c, false);
            for (int j = 0; j < c; j++) {
                cin >> x;
                mat[i][j] = x;
            }
        }
        Solution ob;
        auto ans = ob.maxArea(mat, r, c);
        cout << ans << "\n";

    }
    return 0;
}
  // } Driver Code Ends
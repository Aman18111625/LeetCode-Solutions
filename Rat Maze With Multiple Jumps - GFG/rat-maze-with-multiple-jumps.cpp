// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool isSafe(vector<vector<int>>&mat,int i,int j,int n){
        if(i>=n or j>=n or mat[i][j]==0) return false;
        return true;
    }
    
    bool helper(vector<vector<int>>&mat,vector<vector<int>>&res,int i,int j,int n){
        //reach to destination
        if(i==n-1 && j==n-1){
            res[i][j]=1;
            return true;
        }
        
        if(isSafe(mat,i,j,n)){
            res[i][j]=1;
            //now check for every possible val till mat[i][j].
            for(int k=1;k<=mat[i][j] && k<n ;k++){
                //if anyone of two is give true then we'll return true->it means we can reach the destination
                if(helper(mat,res,i,j+k,n)) return true;
                if(helper(mat,res,i+k,j,n)) return true;
            }
           //not able to reach the destination
             res[i][j]=0;
            return false;
        }
        return false;
    }
public:
	vector<vector<int>> ShortestDistance(vector<vector<int>>&mat){
	   // Code here
	   int n=mat.size();
	   if(mat[0][0]==0 && n!=1) return {{-1}};//we can't move ahead
	   vector<vector<int>>res(n,vector<int>(n,0));//to store res
	   helper(mat,res,0,0,n);
	   return res;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
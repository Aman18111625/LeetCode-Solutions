// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int K){
        // Your code goes here
          for(int i=1; i<N; i++)
          {
              for(int j=0; j<N; j++)
               mat[i][j] += mat[i-1][j];  
          }
            
        for(int i=0; i<N; i++)
        {
           for(int j=1; j<N; j++)
             mat[i][j] += mat[i][j-1];
        }
        
       int res = 0, a, b, c;
        for(int i=K-1; i<N; i++) {
           for(int j=K-1; j<N; j++) {
            a = j == K-1 ? 0 : mat[i][j-K];
            b = i == K-1 ? 0 : mat[i-K][j];
            c = (i == K-1 or j == K-1) ? 0 : mat[i-K][j-K];
            res = max(res, mat[i][j] - a - b + c);
         }
      }
     return res;
   }  
};

// { Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    }
        
    return 0;
}
  // } Driver Code Ends
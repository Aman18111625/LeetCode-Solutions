// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> mat){
        //code here
        pair<int,int>ans;
        int n=mat.size();
        int m=mat[0].size();
        int i=0,j=0;
        char dir='R';
        do{
            if(mat[i][j]==1){
                mat[i][j]=0;
                if(dir=='U') dir='R';
                else if(dir=='R') dir='D';
                else if(dir=='D') dir='L';
                else if(dir=='L') dir='U';
            }
            if(dir=='R') j++;
            else if(dir=='L') j--;
            else if(dir=='U') i--;
            else i++;
        }while(i>=0 && i<n && j>=0 && j<m);
        
        if(dir=='R') j--;
        else if(dir=='L') j++;
        else if(dir=='D') i--;
        else i++;
        ans={i,j};
        return ans;
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends
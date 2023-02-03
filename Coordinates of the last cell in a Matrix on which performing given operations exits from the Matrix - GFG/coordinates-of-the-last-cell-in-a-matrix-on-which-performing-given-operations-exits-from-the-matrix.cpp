//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        int x=0,y=0;
        string dir = "right";

        while (true){
            int old_x = x,old_y = y;
            if(matrix[x][y]==0){
                if(dir == "right"){
                    y++;
                }else if(dir == "left"){
                    y--;
                }else if(dir == "up")
                {
                    x--;
                }else if(dir == "down"){
                    x++;
                }
            }else{
                matrix[x][y]=0;
                if(dir == "right"){
                    dir = "down";
                }else if(dir == "left"){
                    dir = "up";
                }else if(dir == "up")
                {
                   dir = "right";
                }else if(dir == "down"){
                    dir = "left";
                }
            }
            if(x<0 || x>=matrix.size() || y<0 || y>= matrix[0].size()){
                return {old_x,old_y};
            }
        }
    }

};

//{ Driver Code Starts.


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
}
// } Driver Code Ends
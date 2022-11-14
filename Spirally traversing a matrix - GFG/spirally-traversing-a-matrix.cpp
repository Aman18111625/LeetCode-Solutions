//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
        // code here 
        vector<int>ans;
        int top=0,down=r-1,left=0,right=c-1;
        int dir=0,i=0,j=0;
        while(ans.size()!=r*c){
            ans.push_back(mat[i][j]);
            switch(dir){
                case 0:{
                 if(j<right) j++;
                 else {
                     top++;
                     i++;
                     dir++;
                 }
                }break;
                case 1:{
                    if(i<down) i++;
                    else{
                        right--;
                        j--;
                        dir++;
                    }
                }break;
                case 2:{
                    if(j>left) j--;
                    else{
                        down--;
                        i--;
                        dir++;
                    }
                }break;
                case 3:{
                    if(i>top) i--;
                    else{
                        left++;
                        j++;
                        dir=0;
                    }
                }break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
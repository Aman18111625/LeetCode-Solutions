//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // int median(vector<vector<int>> &matrix, int r, int c){
    //     // code here
    //     vector<int>ans;
    //     for(int i=0;i<r;i++){
    //         for(int j=0;j<c;j++){
    //             ans.push_back(matrix[i][j]);
    //         }
    //     }
    //     sort(ans.begin(),ans.end());
    //     return ans[(r*c)/2];
    // }
    
    int getCountOfSmaller(vector<int>&arr,int val){
        int low=0,high=arr.size()-1;
        int ans=0;
        while(low<=high){
            int mid=(low+high)>>1;
            if(arr[mid]<val){
                low=mid+1;
                ans=mid+1;
            }else high=mid-1;
        }
        return ans;
    }
    int median(vector<vector<int>>&mat,int r,int c){
        int low=0,high=1e9;
        int ans=0;
        while(low<=high){
            int mid=(low+high)>>1;
            int count=0;
            for(int i=0;i<r;i++)
             count+=getCountOfSmaller(mat[i],mid);
            if(count<=(r*c)/2){
                ans=mid;
                low=mid+1;
            }else high=mid-1;
        }
        return ans;
    }
};
 

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends
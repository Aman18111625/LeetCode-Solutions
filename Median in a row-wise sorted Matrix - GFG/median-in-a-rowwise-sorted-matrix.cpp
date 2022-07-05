// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    //return how many elements are less than or equal to value
     int helper(vector<int> &arr, int value){
        int low = 0, high = arr.size()-1;
        int len = 0;
        while(low <= high){
            int mid = (low+high) >> 1;
            if(arr[mid] < value){
                len = mid+1;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return len;
    }
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here 
        int low=0,high=1e9;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=0;
            for(int i=0;i<r;i++){
                cnt+=helper(matrix[i],mid);
            }
            if(cnt<=(r*c)/2){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

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
}  // } Driver Code Ends
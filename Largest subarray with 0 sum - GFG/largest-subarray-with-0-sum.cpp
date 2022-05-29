// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        // Your code here
        // int ans=0;
        // for(int i=0;i<n; i++){
        //     int curr=0;
        //     for(int j=i;j<n;j++){
        //         curr+=nums[j];
        //         if(curr==0) {
        //             ans=max(ans,j-i+1);
        //         }
        //     }
        // }
        // return ans;
        unordered_map<int,int>mpp;
        int maxi=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==0){
                maxi=i+1;
            }else{
                if(mpp.find(sum)!=mpp.end()){
                    maxi=max(maxi,i-mpp[sum]);
                }else{
                    mpp[sum]=i;
                }
            }
        }
        return maxi;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends
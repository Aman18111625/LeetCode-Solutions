// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    int helper(vector<int>&nums,int ind,int limit,int rl,vector<vector<int>>&dp){
        if(ind==nums.size()-1){
            if(nums[ind]<rl) return dp[ind][rl]=0;
            return  dp[ind][rl]=rl*rl;
        }
        if(dp[ind][rl]!=-1) return dp[ind][rl];
        if(nums[ind]<rl){
            int take= helper(nums,ind+1,limit,rl==limit?rl-nums[ind]: rl-nums[ind]-1,dp);
            int notTake=rl*rl + helper(nums,ind+1,limit,limit-nums[ind],dp);
            return dp[ind][rl]=min(take,notTake);
        }else{
            return dp[ind][rl]=rl*rl+helper(nums,ind+1,limit,limit-nums[ind],dp);
        }
    }
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return helper(nums,0,k,k,dp);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends
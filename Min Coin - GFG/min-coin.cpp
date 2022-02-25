// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    vector<int>dp(amount+1,INT_MAX);
	    dp[0]=0;
	    int n=nums.size();
	    for(int i=1;i<=amount;i++){
	        for(int j=0;j<n;j++){
	            if(i>=nums[j]){
	                if(dp[i-nums[j]]!=INT_MAX){
	                    dp[i]=min(1+dp[i-nums[j]],dp[i]);
	                }
	            }
	        }
	    }
	    return dp[amount]==INT_MAX?-1:dp[amount];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
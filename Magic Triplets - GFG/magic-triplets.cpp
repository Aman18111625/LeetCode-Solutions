//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    int n=nums.size();
	    int cnt=0;
	    for(int j=1;j<n-1;j++){
	        int smaller=0;
	        for(int i=j-1;i>=0;i--){
	            if(nums[i]<nums[j]) smaller++;
	        }
	        int larger=0;
	        for(int k=j+1;k<n;k++){
	            if(nums[j]<nums[k]) larger++;
	        }
	        cnt+=(smaller*larger);
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends
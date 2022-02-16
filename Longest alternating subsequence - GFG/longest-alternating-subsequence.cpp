// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		     int n= nums.size();
		     int maxi= 1, mini= 1;
		    for (int i=1; i<n; i++){
		        if (nums[i] > nums[i-1]){
		            maxi= mini+1;
		        }
		      else if(nums[i] < nums[i-1]){
		          mini= maxi+1;
		      }
		       else
		        continue;
		    }
		    return max (maxi, mini);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
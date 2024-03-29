// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    //basically we have to think greedily.
	int minSwaps(vector<int>&nums){
	    // Code here
	    int n=nums.size();
	    vector<pair<int,int>>ans(n);
	    for(int i=0;i<n;i++)
	        ans[i]={nums[i],i};
	        
	    sort(ans.begin(),ans.end());
	    int res=0;
	    for(int i=0;i<n;i++){
	        //if ans[i] is not the correct position so we have to swap it till it reaches to right index
	       if(ans[i].second!=i){
	            res++;
	            swap(ans[i],ans[ans[i].second]);
	            i--;
	       }
	    }
	    return res;
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
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
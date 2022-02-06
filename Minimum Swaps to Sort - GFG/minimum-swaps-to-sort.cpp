// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    vector<pair<int,int>>ans(n);
	    vector<bool>vis(n,false);
	    for(int i=0;i<n;i++)
	    {
	        ans[i]={nums[i],i};
	    }
	    sort(ans.begin(),ans.end());
	    int res=0;
	    for(int i=0;i<n;i++)
	    {
	        if(vis[i] || ans[i].second==i)//already visited or already in correct position
	         continue;
	        int j=i,size=0;
	        while(!vis[j])
	        {
	            vis[j]=true;
	            j=ans[j].second;
	            size++;
	        }
	        if(size>0)
	        res+=(size-1);
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
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    void recur(vector<vector<int>>&ans,int num,int target,vector<int>&temp){
        if(target==0) {
            ans.push_back(temp);
            return ;
        }
        
        if(num==0) return;
        if(target>=num){
            temp.push_back(num);
            recur(ans,num,target-num,temp);
            temp.pop_back();
        }
        recur(ans,num-1,target,temp);
    }
	public:
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<vector<int>>ans;
        vector<int>temp;
        recur(ans,n,n,temp);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends
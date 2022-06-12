// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int helper(string &s,int ind,int prevSum,vector<vector<int>>&dp){
        if(ind==s.size()) return 1;
        if(dp[ind][prevSum]==-1) {
        dp[ind][prevSum]=helper(s,ind+1,prevSum+(s[ind]-'0'),dp);
        int sum=0;
        for(int j=ind;j<s.size();j++){
            sum+=(s[j]-'0');
            if(sum>=prevSum){
              dp[ind][prevSum]+=helper(s,j+1,sum,dp);
               break;   
            }
        }
      }
      return dp[ind][prevSum];
    }
	public:
	int TotalCount(string str){
	    // Code here
	    int sumOfDigits=0;
	    for(auto ch : str){
	        sumOfDigits+=(ch-'0');
	    }
	    int n=str.size();
	    vector<vector<int>>dp(n,vector<int>(sumOfDigits+1,-1));
	    return helper(str,1,str[0]-'0',dp);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
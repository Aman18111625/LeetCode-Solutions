// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	  void printAllCombinations(string s,int start,int end,vector<string>&ans){
	        if(start==end){
	             ans.push_back(s);
	             return ;
	        }
	        for(int i=start;i<=end;i++){
	             swap(s[start],s[i]);
	             printAllCombinations(s,start+1,end,ans);
	             swap(s[start],s[i]);
	        }
	        
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    printAllCombinations(S,0,S.length()-1,ans);
		    map<string,int>hash;
		    for(auto it : ans) hash[it]++;
		    ans.clear();
		    for(auto it : hash) ans.push_back(it.first);
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
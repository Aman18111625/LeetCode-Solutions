//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{ 
    void helper(string s,int start,int end,unordered_set<string>&st){
        if(start==end){
            st.insert(s);
            return ;
        }
        for(int i=start;i<=end;i++){
            swap(s[start],s[i]);
            helper(s,start+1,end,st);
            swap(s[start],s[i]);
        }
    }
	public:
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string>ans;
		    unordered_set<string>st;
		    int n=s.size();
		    for(int i=0;i<n;i++){
		        helper(s,i,n-1,st);
		    }
		    for(auto it: st) ans.push_back(it);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
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
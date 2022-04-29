// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
// to find distinct element in given range
   int findDistinct(string s, int l ,int r){
       set<char>st;
    // we push characters in set 
       for(int i=l;i<=r;i++){
           st.insert(s[i]);
       }    
       return st.size();
    }
    vector<int>SolveQueris(string str, vector<vector<int>>Query){
       vector<int> ans;
           for(int i=0;i<Query.size();i++){
               int k=0;
               int l = Query[i][0];
               int r = Query[i][1];
               // call the finction finding distinct characters in                            // substring
                k = findDistinct(str,l-1,r-1);    
                ans.push_back(k);
           }
       return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
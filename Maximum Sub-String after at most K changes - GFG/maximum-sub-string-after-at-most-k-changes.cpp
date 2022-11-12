//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    int i=0,j=0;
		    int n=s.size();
		    int ans=0,maxi=0;
		    unordered_map<char,int>map;
		    while(j<n){
		        map[s[j]]++;
		        maxi=max(maxi,map[s[j]]);
		        int need=j-i+1-maxi;//widnow size- element with maxFreq
		        if(need<=k) ans=max(ans,j-i+1);//it can be possible answer
		        else {
		            map[s[i]]--;
		            i++;//reduce the size of window
		        }
		        j++;
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
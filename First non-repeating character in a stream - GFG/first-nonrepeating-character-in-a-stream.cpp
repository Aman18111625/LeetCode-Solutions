// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int>freq(26,0);
		    string ans;
		    vector<char>v;
		    int n=A.size();
		    for(int i=0;i<n;i++){
		        if(!freq[A[i]-'a']){
		            v.push_back(A[i]);
		        }
		        freq[A[i]-'a']++;
		        int flag=1;
		        int m=v.size();
		        for(int j=0;j<m;j++){
		            if(freq[v[j]-'a']==1){
		                ans+=v[j];
		                flag=0;
		                break;
		            }
		        }
		        if(flag) ans.push_back('#');
		    }
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int len = A.size();
            string res;
            int arr[26]={0};
            int j,i;
            queue<char> q;
            for(i=0;i<len;i++){
               int index = A[i]-'a';
               q.push(A[i]);
               arr[index]++;
               int check=0;
               while(!q.empty()){
                   char c = q.front();
                   index = c-'a';
                   if(arr[index]==1){
                       res+=c;
                       check=1;
                       break;
                   }
                   q.pop();
                }
                if(check==0) 
                   res.push_back('#');
            }
            return res;
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
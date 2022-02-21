// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*Returns an array of all n-bit gray codes sequence.
You are required to complete below method. */
class Solution{
  public:
    vector<string>generateCode(int N)
    {
         //Your code here
         vector<string>ans;
         if(N==0) return ans;
         ans.push_back("0");
         ans.push_back("1");
         if(N==1) return ans;
         int curr=1;
         for(int i=2;i<=N;i++){
            
            for(int j = 0; j < pow(2,i-1); j++) 
                ans.push_back(ans[pow(2,i-1)-1-j]);
                
            for(int j=0;j<pow(2,i);j++){
                if(j<pow(2,i-1)){
                    ans[j]='0'+ans[j];
                }else{
                    ans[j]='1'+ans[j];
                }
            }
         }
         return ans;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution obj;
		vector <string> res = obj.generateCode(n);
		for (string i : res) cout << i << " ";
        cout<<endl;
	}
	return 0;
}

  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	    int i=A.size()-1,j=B.size()-1;
	    int carry=0;
	    string ans="";
	    while(i>=0 || j>=0 || carry){
	        int sum=0;
	        if(i>=0){
	            sum+=(A[i]-'0');
	            i--;
	        }
	        if(j>=0){
	            sum+=(B[j]-'0');
	            j--;
	        }
	        sum+=carry;
	        ans+=to_string(sum%2);
	        carry=sum/2;
	    }
	    //to remove leading zeros
	    int k=ans.size()-1;
	    while(ans[k]!='1'){
	        ans.pop_back();
	        k--;
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
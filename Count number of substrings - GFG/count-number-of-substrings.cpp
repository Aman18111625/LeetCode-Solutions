// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
    long long int helper(string s,int k){
        if(s.size()==0 or k==0) return 0;
        long long int i=0,j=0,cnt=0,n=s.size(),res=0;
        int freq[26]={0};
       while(j<n){
           freq[s[j]-'a']++;
           if(freq[s[j]-'a']==1) cnt++;
           while(i<j && cnt>k){
               freq[s[i]-'a']--;
               if(freq[s[i]-'a']==0) cnt--;
               i++;
           }
           res+=(j-i+1);
           j++;
       }
       return res;
    }
  public:
    long long int substrCount (string s, int k) {
    	//code here.
    	return helper(s,k)-helper(s,k-1);
    }
};

// { Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}  // } Driver Code Ends
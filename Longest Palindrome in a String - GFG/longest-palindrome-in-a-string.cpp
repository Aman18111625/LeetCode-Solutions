// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
   int solve(string s,int left,int right){
       if(s.size()==0 or left>right) return 0;
       while(left>=0 && right<s.size() && s[left]==s[right]){
           left--;
           right++;
       }
       return right-left-1;
   }
  
    string longestPalin (string s) {
        // code here
        int n = s.size();
        if(n<=1) return s;
        int start=0,end=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int len1=solve(s,i,i);//for odd palindrome i.e. racecar
            int len2=solve(s,i,i+1);//for even palindrome i.e. aabbaa
            int len=max(len1,len2);
            if(len>ans){
                ans=len;
                start=i-((len-1)/2);//starting position of palindrome string
                end=i+(len/2);//ending position of palindrome string
            }
        }
        int a=end-start+1;
        return s.substr(start,a);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
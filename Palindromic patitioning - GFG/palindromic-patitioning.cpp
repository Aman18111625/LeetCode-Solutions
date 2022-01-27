// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
     int dp[1001][1001];
    bool isPalindrome(string& str,int start,int end)
    {
         while(start<=end)
         {
            if(str[start++]!=str[end--]) return false;
         }
         return true;
    }
    int helper(string& str,int i,int j)
    {
        if(i>=j) return 0;
        if(isPalindrome(str,i,j)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp=1+helper(str,i,k)+helper(str,k+1,j);
            if(temp<mini) mini=temp;
        }
        return dp[i][j]=mini;
    }
public:
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        if(isPalindrome(str,0,str.size()-1)) return 0;
        return helper(str,0,str.size()-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
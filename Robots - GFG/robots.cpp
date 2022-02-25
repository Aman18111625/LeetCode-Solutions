// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
/*
Thought Process:=>
we'll store char as key and it's index as value into stack while char!='#'.
our stack.top() must contian the same character .
For char A it must have occur before this (index≥i) .
For char B it must occur after this. (index≤i)
*/
    string moveRobots(string s1, string s2){
        // code here 
        if(s1==s2) return "Yes";
        stack<pair<char,int>>s;
        int n=s1.size();
      
      for(int i=0;i<n;i++)
      {   
          if(s1[i]!='#')
          s.push({s1[i],i});
      }
      
      for(int i=n-1;i>=0;i--)
      {
        if(s2[i]=='#') continue;
        if(s.empty() || s.top().first!=s2[i]) return "No";
        if(s2[i]=='A' and s.top().second>=i) s.pop();
        if(s2[i]=='B' and s.top().second<=i) s.pop();
        
      }
      return s.empty()?"Yes":"No";
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        
        Solution ob;
        cout << ob.moveRobots(s1, s2) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
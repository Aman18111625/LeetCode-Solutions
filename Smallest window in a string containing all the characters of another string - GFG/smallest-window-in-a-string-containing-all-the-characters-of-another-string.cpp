// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int>freq(256,0);
        int count=0;
        for(auto ch : p){
            if(freq[ch-'a']==0) count++;
            freq[ch-'a']++;
        }
        int n=s.size(),res=INT_MAX;
        int i=0,j=0,start=0;
        while(j<n){
            freq[s[j]-'a']--;
            if(freq[s[j]-'a']==0) count--;
            if(count==0){//i got all distinct character of string p
              while(count==0){
                  if(j-i+1<res){
                      res=(j-i+1);
                      start=i;
                  }
                  freq[s[i]-'a']++;
                  if(freq[s[i]-'a']==1) count++;
                  i++;
              }
            }
            j++;
        }
        return res==INT_MAX?"-1":s.substr(start,res);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
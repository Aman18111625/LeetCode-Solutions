// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        //code here.
         string ans="";
         int num=0;
         for(auto &it: str)
         {
             if(isdigit(it)) num+=(it-'0');
             else ans+=it;
         }
         sort(ans.begin(),ans.end());
         ans+=to_string(num);
         return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends
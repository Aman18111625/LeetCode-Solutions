// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string remove(string s){
        // code here
        /*
        while(1){
            int n=s.size(),i=0;
            string temp="";
            while(i<n){
                int j=i;
                while(++j<n && s[i]==s[j]);
                if(j==i+1) temp+=s[i];
                i=j;
            }
            if(s.size()==temp.size()) break;
            s=temp;
        }
        return s;*/
      int n=s.size();
      if(n<=1) return s;
      int cnt=0;//store how many different character
      for(int i=0;i<n-1;i++){
           if(s[i]!=s[i+1]) cnt++;
       }
       if(cnt==n-1) return s;//now there is no adjacent duplicate character
       int i=0;
       string ans="";
       while(i<n-1){
           if(s[i]!=s[i+1]){
               ans.push_back(s[i]);
               i++;
               continue;
           }
           int st=i;
           //remove duplicats
           while(i<n and s[i]==s[st])i++;
       }
       //for last character
        if(i==n-1){
          ans.push_back(s[i]);
          i++;
        }
        //now again  check for string ans 
        return remove(ans);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends
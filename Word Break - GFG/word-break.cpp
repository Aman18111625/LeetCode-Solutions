//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
   bool solve(unordered_map<string, int> &mp, int i, string &A){
        if(i == A.length()) return true;
        string temp = "";
        while(i < A.length()) {
            temp += A[i++];
            if (mp.find(temp) != mp.end() && solve(mp, i, A)) return true;
        }
        return false;
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map<string, int> mp;
        for(string s: B)
            mp.insert({s, 1});
        return solve(mp, 0, A) == true;    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
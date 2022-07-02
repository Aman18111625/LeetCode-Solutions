// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void helper(string &s,set<string>&dict,vector<string>&ans,string curr,int ind){
        if(ind>s.size()) return ;
        if(ind==s.size()){
            curr.pop_back();
            ans.push_back(curr);
            return ;
        }
        for(int k = ind; k < s.size(); k++){
           string temp = s.substr(ind, k - ind + 1);
           if(find(dict.begin(), dict.end(), temp) != dict.end())
           helper( s,dict,ans,curr + temp + ' ',k+1);
       }
        
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string>ans;
        set<string>dictionary;
        for(auto &word : dict) dictionary.insert(word);
        helper(s,dictionary,ans,"",0);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
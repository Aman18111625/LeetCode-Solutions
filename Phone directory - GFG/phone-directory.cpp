// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        sort(contact,contact+n);
        vector<vector<string>>ans;
        int size=s.size();
        for(int i=0;i<size;i++){
            string temp=s.substr(0,i+1);
            set<string>st;
            for(int j=0;j<n;j++){
                string curr=contact[j].substr(0,i+1);
                if(curr==temp){
                    st.insert(contact[j]);
                }
            }
            if(!st.empty()){
                ans.push_back({st.begin(),st.end()});
            }else{
                ans.push_back({"0"});
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
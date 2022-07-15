// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    struct Node{
      int cnt{0};//store occurance of every char 
      Node* children[26]={0};
    };
    //insert into trie
    void insert(Node* root,string& word){
        for(auto ch: word){
            int c=ch-'a';
            if(!root->children[c]) root->children[c]= new Node();
            root->cnt++;
            root=root->children[c];
        }
    }
    //if occurance of a char is 1 then it'll be our smallest prefix otherwise we'll add character
    //in our answer till we get  a char whose occurance is 1 or till end of the string
    string getPrefix(Node* root,string& word)
    {
        string prefix="";
        for(auto &ch: word){
            int c=ch-'a';
            if(root->cnt==1) break;
            prefix+=ch;
            root=root->children[c];
        }
        return prefix;
    }
    
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        Node* trie=new Node();
        for(int i=0;i<n;i++)
          insert(trie,arr[i]);
          
        vector<string>ans;
        for(int i=0;i<n;i++)
         ans.push_back(getPrefix(trie,arr[i]));
          
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends
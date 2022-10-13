//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        if(str1.size()!=str2.size()) return false;
        unordered_map<char,int>map1,map2;
        for(auto ch: str1) map1[ch]++;
        for(auto ch: str2) map2[ch]++;
        
        for(int i=0;i<str1.size();i++){
            if(map1[str1[i]]!=map2[str2[i]])
              return false;
            map1[str1[i]]--;
            map2[str2[i]]--;
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
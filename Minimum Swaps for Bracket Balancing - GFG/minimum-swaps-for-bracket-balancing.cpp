//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        // code here 
    vector<int> pos;
    int n=s.size();
    for (int i = 0; i < n ; i++)
        if (s[i] == '[')
          pos.push_back(i);
 
    int count=0,p=0,sum=0;
    for (int i = 0; i < n; ++i){
        if(s[i]=='['){
            count++;
            p++;
        }
        else if (s[i] == ']')
            count--;
 
        if (count < 0){
            sum += pos[p] - i;
            swap(s[i], s[pos[p]]);
            p++;
            count = 1;
        }
     }
     return sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
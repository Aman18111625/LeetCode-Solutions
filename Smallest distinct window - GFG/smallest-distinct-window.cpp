// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        if(str.size()==1) return 1;
        set<char>st(str.begin(),str.end());
        int len=st.size();
        int i=0,j=1,cnt=1;
        int ans=INT_MAX;
        unordered_map<char,int>freq;
        freq[str[i]]++;
        while(i<=j && j<str.size()){
            if(cnt<len){
                if(freq[str[j]]==0) cnt++;
                freq[str[j]]++;
                j++;
            }
            
            while(cnt==len){
                ans=min(ans,j-i);
                if(freq[str[i]]==1) cnt--;
                freq[str[i]]--;
                i++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends
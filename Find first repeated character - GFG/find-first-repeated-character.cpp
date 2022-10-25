//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    vector<int>freq(26,0);
    string ans;
    for(auto ch : s) {
        if(freq[ch-'a']==1){
            string ans;
            return ans+=ch;
        }
        freq[ch-'a']++;
    }
    return "-1";
}
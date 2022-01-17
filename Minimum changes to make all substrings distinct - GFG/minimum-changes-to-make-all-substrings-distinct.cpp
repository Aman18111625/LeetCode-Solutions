// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minChange(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << minChange(s) << endl;
    }
return 0;
}
// } Driver Code Ends


int minChange(string S) { 
     //complete the function here
     int freq[26]={0};
     int dist=0;
     for(auto ch : S)
     {
         freq[ch-'a']++;
         if(freq[ch-'a']>1) dist++;
     }
     return dist;
} 

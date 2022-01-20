// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    
    long long int countOfSubstringWithKOnes(string S, int K){
        //complete the function here
        unordered_map<int,int>mpp;
        int res=0,num=0;
        mpp[0]++;
        for(auto it: S)
        {
            num+=(it-'0');
            if(num>=K) res+=mpp[num-K];
            mpp[num]++;
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
       string s;
       int k;
       cin >> s >> k;
       Solution ob;
       cout << ob.countOfSubstringWithKOnes(s, k) << endl;
    }
return 0;
}

  // } Driver Code Ends
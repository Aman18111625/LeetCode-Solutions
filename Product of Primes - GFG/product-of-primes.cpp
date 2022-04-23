// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    bool isPrime(long long int n){
        if(n==0 or n==1) return false;
        bool ans=true;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                ans=false;
                break;
            }
        }
        return ans;
    }
public:
    long long primeProduct(long long L, long long R){
        // code here
        long long int Mod=1e9+7;
        long long int ans=1;
        for(int i=L;i<=R;i++){
            if(isPrime(i)) {
                ans*=i%Mod;
                ans%=Mod;
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
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
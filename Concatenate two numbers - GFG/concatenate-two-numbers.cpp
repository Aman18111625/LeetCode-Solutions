// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long countPairs(int N, int X, vector<int> numbers){
       map<int,int>mpp;
       for(auto &num: numbers) mpp[num]++;
       long long cnt=0;
       for(auto &it : mpp){
           int p=it.first;
           int q=X;
           bool flag=true;
           while(p){
               if(p%10!=q%10){
                   flag=false;
                   break;
               }
               p/=10;
               q/=10;
           }
           if(!flag) continue;
          // cout<<q<<"%";
           if(q==it.first) cnt+=(mpp[q]*(mpp[q]-1));
           else cnt+=(mpp[q]*it.second);
       }
       return cnt;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
       int n=A.size();
       int m=B.size();
       if(n!=m) return -1;
       int i=n-1,j=m-1;
       map<char,int> m1;
       map<char,int> m2;
       for(int k=0;k<=i;k++){
           m1[A[k]]++;
           m2[B[k]]++;
        }
       if(m1!=m2) return -1;
       int cnt=0;
       while(i>=0 && j>=0){
           if(A[i]==B[j]){
               i--;
               j--;
           }
           else{
               while(A[i]!=B[j] && i>=0 && j>=0){
                   i--;
                   cnt++;
               }
           }
       }
       return cnt;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends
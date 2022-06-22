// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
   long factorial(int n){
       int fact=1;
       for(int i=1;i<=n;i++) fact*=i;
       return fact;
   }
   
     
    long posIntSol(string s)
    {
       int n=0;
       int index=0;
       for(int i=0;i<s.size();i++){
           if(s[i]=='+') n++;
           if(s[i]=='=') index=i;
       }
       string sub=s.substr(index+1);
       int k=stoi(sub);
       k--;
       long num=1;
       for(int i=1;i<=n;i++){
           num*=k;
           k--;
       }
       long deno=factorial(n);
       return num/deno;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
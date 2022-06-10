// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        double binary_search(double L,double R,int n,double magnets[]){
          double force=0.0;
          double mid=(L+R)/2.0;
          for(int i=0;i<n;i++){
              force+=(1.0/(mid-magnets[i]));
          }
          if(abs(force)<1e-12) return mid;
          else if(force<0) binary_search(L,mid,n,magnets);
          else if(force>0) binary_search(mid,R,n,magnets);
        }
        
        void nullPoints(int n, double magnets[], double getAnswer[]){
        // Your code goes here   
        for(int i=0;i<n-1;i++){
            getAnswer[i]=binary_search(magnets[i],magnets[i+1],n,magnets);
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
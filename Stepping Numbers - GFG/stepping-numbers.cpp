// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    bool check(int num){
        stack<int>st;
        while(num){
            int rem=num%10;
            if(st.empty()) st.push(rem);
            else{
                if(abs(st.top()-rem)!=1) return false;
                else st.push(rem);
            }
            num/=10;
        }
        return true;
    }
public:
    int steppingNumbers(int n, int m)
    {
        // Code Here
        int cnt=0;
        for(int i=n;i<=m;i++) if(check(i)) cnt++;
        return cnt;
    }
};


// { Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}

  // } Driver Code Ends
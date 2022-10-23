//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    int steppingNumbers(int n, int m)
    {
        // Code Here
        int ans=0;
        queue<int> q;
        for(int i=0;i<=9;i++){
            q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(curr>=n&&curr<=m){
                ans++;
            }
            if(curr==0||curr>=m)continue;
            int ld=curr%10;
            int step1=curr*10+(ld-1);
            int step2=curr*10+(ld+1);
            if(ld==0)q.push(step2);
            else if(ld==9)q.push(step1);
            else{
                q.push(step1);
                q.push(step2);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

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
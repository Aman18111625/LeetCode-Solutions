// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	     int s1=KnightPos[0];
	    int t1=KnightPos[1];
	    int s2=TargetPos[0];
	    int t2=TargetPos[1];
	    
	    int vis[1001][1001];
	    if(s1==s2 and t1==t2) return 0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            vis[i][j]=0;
	        }
	    }
	    queue<pair<int,int>>q;
	    q.push({s1-1,t1-1});
	    while(!q.empty())
	    {
	        auto cur=q.front();
	        int i=cur.first;
	        int j=cur.second;
	        q.pop();
	        if(i+1>=0 and i+1<n and j+2>=0 and j+2<n and vis[i+1][j+2]==0)
	        {
	            vis[i+1][j+2]=vis[i][j]+1;
	            q.push({i+1,j+2});
	        }
	         if(i-1>=0 and i-1<n and j+2>=0 and j+2<n and vis[i-1][j+2]==0)
	        {
	            vis[i-1][j+2]=vis[i][j]+1;
	            q.push({i-1,j+2});
	        }
	         if(i-2>=0 and i-2<n and j+2>=0 and j+1<n and vis[i-2][j+1]==0)
	        {
	            vis[i-2][j+1]=vis[i][j]+1;
	            q.push({i-2,j+1});
	        } if(i+2>=0 and i+2<n and j+1>=0 and j+1<n and vis[i+2][j+1]==0)
	        {
	            vis[i+2][j+1]=vis[i][j]+1;
	            q.push({i+2,j+1});
	        } if(i-1>=0 and i-1<n and j-2>=0 and j-2<n and vis[i-1][j-2]==0)
	        {
	            vis[i-1][j-2]=vis[i][j]+1;
	            q.push({i-1,j-2});
	        } if(i+1>=0 and i+1<n and j-2>=0 and j-2<n and vis[i+1][j-2]==0)
	        {
	            vis[i+1][j-2]=vis[i][j]+1;
	            q.push({i+1,j-2});
	        }
	         if(i-2>=0 and i-2<n and j-1>=0 and j-1<n and vis[i-2][j-1]==0)
	        {
	            vis[i-2][j-1]=vis[i][j]+1;
	            q.push({i-2,j-1});
	        }
	         if(i+2>=0 and i+2<n and j-1>=0 and j-1<n and vis[i+2][j-1]==0)
	        {
	            vis[i+2][j-1]=vis[i][j]+1;
	            q.push({i+2,j-1});
	        }
	    }
	    return vis[s2-1][t2-1];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
void bfs(vector<vector<char> >& matrix, int M, int N, int i, int j,vector<vector<int>>&v){
        queue<pair<pair<int, int>,int>>q;
        q.push({{i,j},0});
        int ans = -1;
        vector<vector<bool>>visited(M, vector<bool>(N, false));
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            visited[r][c] = true;
            if(matrix[r][c] == 'B'){
                ans = distance;
                break;
            }
            int nr[] = {r+1,r-1,r,r};
            int nc[] = {c,c,c+1,c-1};
            for(int x = 0;x<4;x++){
                if(nr[x]<0 || nc[x]<0 || nr[x]>=M || nc[x]>=N)continue;
                if(matrix[nr[x]][nc[x]] == 'W' || visited[nr[x]][nc[x]] == true)continue;
                
                q.push({{nr[x], nc[x]}, distance + 1});
                
            }
        }
        v[i][j] = ans;
    }
    
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        vector<vector<int>>v(M, vector<int>(N, -1));
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if(matrix[i][j] == 'B')v[i][j] = 0;
                else if(matrix[i][j] == 'O'){
                    bfs(matrix, M, N,i,j,v);
                }
            }
        }
        return v;
    }
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends
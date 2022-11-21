class Solution {
public:
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>>q;
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>>vis(n,vector<int>(m)),dis(n,vector<int>(m));
        q.push({entrance[0],entrance[1]});
        vis[entrance[0]][entrance[1]]=1;
        dis[entrance[0]][entrance[1]]=0;
      
        int dx[4] ={-1,1,0,0};
        int dy[4] ={0,0,-1,1};
        while(!q.empty()){
            pair<int,int> f=q.front();
            q.pop();
            if((f.first==0 || f.second==0 || f.first==n-1 || f.second==m-1)
               && !(f.first==entrance[0] && f.second==entrance[1]))  {
             return dis[f.first][f.second];    
            }
            for(int k=0;k<4;k++){
                int nx=f.first+dx[k],ny=f.second+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && maze[nx][ny]=='.' && !vis[nx][ny]) {
                    q.push({nx,ny});
                    dis[nx][ny]=dis[f.first][f.second]+1;
                    vis[nx][ny]=1;
                }
            }
        }
        return -1;   
    }
};
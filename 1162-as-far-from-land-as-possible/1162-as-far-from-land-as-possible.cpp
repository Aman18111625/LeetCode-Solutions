class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        bool flag=false;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(grid[i][j]==1){
                    q.push({i,j});
                }
                else flag=true;
        }
        int count=0;
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            count++;
            int size=q.size();
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nx=dir[i].first;
                    int ny=dir[i].second;
                    
                    if((x+nx)<0 || (x+nx)>=n || (y+ny)<0 || (y+ny)>=n)continue;
                    if(grid[x+nx][y+ny]==1) continue;
                    grid[x+nx][y+ny]=1;
                    q.push({x+nx,y+ny});
                }
            }
        }
        if(!flag) return -1;
        return count-1;
    }
};
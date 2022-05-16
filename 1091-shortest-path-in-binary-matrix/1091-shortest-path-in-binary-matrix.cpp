class Solution {
public:
    //BFS Approach
    //Time-Complexity:=>O(N*N)
    //Space-Complexity:=>O(N*N)
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         int n=grid.size();
         if(n==0) return -1;
         //;//base case =>if source or destination does not have 0 
         if (grid[0][0] != 0 or grid[n-1][n-1] != 0) return -1;
          //All possible directions
vector<vector<int>>directions = {{1,1},{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};
          queue<pair<int,int>>q;
          q.push({0,0});
          grid[0][0]=1;
        while(!q.empty()){
            auto temp=q.front();q.pop();
            int x=temp.first,y=temp.second;
            if(x==n-1 and y==n-1) return grid[x][y];//reaches to destination
            for(auto dir : directions){
                int nx=x+dir[0];
                int ny=y+dir[1];
                //check validity
                if(nx>=0 and nx<n and ny>=0 and ny<n and grid[nx][ny]==0){
                    q.push({nx,ny});
                    grid[nx][ny]=1+grid[x][y];
                }
            }
        }
        return -1;
    }
};
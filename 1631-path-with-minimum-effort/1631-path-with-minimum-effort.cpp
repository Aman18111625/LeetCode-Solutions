/*
#define pii pair<int, pair<int,int>>
class Solution {
  const int dir_x[4]={-1,0,1,0};
  const int dir_y[4]={0,1,0,-1};
public:
  //TC=>O(M*N(log(M*N)))
  //SC=>O(M*N)
    int minimumEffortPath(vector<vector<int>>& h) {
       int n=h.size(),m=h[0].size();
       
      //min-heap 
      priority_queue<pii,vector<pii>,greater<pii>>pq;
      //to store distances from (0,0)
      vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
      dist[0][0]=0;
      //{distance,{row,col}}
      pq.push({0,{0,0}});
      //Dijstra Algorithm
      while(!pq.empty()){
        pii curr=pq.top();
        pq.pop();
        int d=curr.first,r=curr.second.first,c=curr.second.second;
        //bottom right position
        if(r==n-1 && c==m-1) return d;
        for(int i=0;i<4;i++){
          int new_x=r+dir_x[i],new_y=c+dir_y[i];
          //check if new position is invalid
          if(new_x<0 or new_x>=n or new_y<0 or new_y>=m) continue;
          int new_distance=max(d,abs(h[new_x][new_y]-h[r][c]));
          if(new_distance<dist[new_x][new_y]){
            dist[new_x][new_y]=new_distance;
            pq.push({new_distance,{new_x,new_y}});
          }
        }
      }
      return 0;
    }
};
*/
class Solution{
  public:
  
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
	
    bool isvalid(int x,int y,int n, int m){
    return (x>=0 && x<n && y>=0 && y<m);
    }
    bool bfs(vector<vector<int>> heights,int k) {
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        vector<vector<bool>>visited(101,vector<bool>(101,false));
        visited[0][0]=1;
		
        while(!q.empty()) {
        pair<int,int>curr = q.front();
        q.pop();
        int cx = curr.first;
        int cy = curr.second; 
        if(cx == heights.size()-1 && cy==heights[0].size()-1)
            return true;
        for(int i=0;i<4;i++) {
            int x = dx[i] + cx;
            int y = dy[i] + cy;
            if(isvalid(x,y,heights.size(),heights[0].size()) && !visited[x][y] ){
                if( abs(heights[cx][cy]-heights[x][y]) <= k){
                    visited[x][y] = true;
                    q.push(make_pair(x,y));
                }
            }
        }
     }
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l=0;
        int r = 1e6;
        while(l<r) {
            int m = l+(r-l)/2;
            if(bfs(heights,m))
                r=m;
            else 
                l=m+1;
        }
        return l;
    }
};

 
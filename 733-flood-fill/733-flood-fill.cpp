class Solution {
public: 
    //BFS Approach
    // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
    //         int m=image.size(),n=image[0].size();
    //         vector<vector<int>>vis(m,vector<int>(n,0));
    //         queue<pair<int,int>>pq;
    //         pq.push({sr,sc});
    //         vis[sr][sc]=1;
    //         while(!pq.empty()){
    //            auto temp=pq.front(); pq.pop();
    //            int i=temp.first,j=temp.second;
    //            if(i-1>=0 && image[i-1][j]==image[i][j] && vis[i-1][j]==0){
    //             vis[i][j]=1;
    //             pq.push({i-1,j});
    //            }
    //            if(j-1>=0 && image[i][j-1]==image[i][j] && vis[i][j-1]==0){
    //             vis[i][j-1]=1;
    //             pq.push({i,j-1});
    //            }
    //            if(i+1<m && image[i+1][j]==image[i][j] && vis[i+1][j]==0){
    //             vis[i+1][j]=1;
    //             pq.push({i+1,j});
    //            }
    //            if(j+1<n && image[i][j+1]==image[i][j] && vis[i][j+1]==0){
    //             vis[i][j+1]=1;
    //             pq.push({i,j+1});
    //            }
    //           image[i][j]=newColor;
    //       }
    //       return image;
    // }
  
  //DFS Approach
  void dfs(vector<vector<int>>&image,int sr,int sc,int newColor,int curr){
    int n=image.size(),m=image[0].size();
    //boundary cases and if not to curr color or alredy filled with new-color
    if(sr<0 or sr>=n or sc<0 or sc>=m or image[sr][sc]!=curr or image[sr][sc]==newColor) return ;
    image[sr][sc]=newColor;//filled with new-color
    //now go to all four direction
    dfs(image,sr-1,sc,newColor,curr);
    dfs(image,sr+1,sc,newColor,curr);
    dfs(image,sr,sc-1,newColor,curr);
    dfs(image,sr,sc+1,newColor,curr);
  }
  
  vector<vector<int>> floodFill(vector<vector<int>>&image,int sr,int sc,int newColor){
       int curr=image[sr][sc];
       dfs(image,sr,sc,newColor,curr);
       return image;
  }
  
};
  
  

	
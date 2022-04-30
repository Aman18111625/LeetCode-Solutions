class Solution {  
    void dfs(vector<vector<int>>&mat, int i,int j,int& m,int& n, int dir){
      if(i<0 or j<0 or i>=m or j>=n) return ;
      if(mat[i][j]==2 or mat[i][j]==1) return ;
      mat[i][j]=3;
      if(dir==1){
        dfs(mat,i+1,j,m,n,dir);
      }else if(dir==2){
        dfs(mat,i,j+1,m,n,dir);
      }else if(dir==3){
        dfs(mat,i-1,j,m,n,dir);
      }else{
        dfs(mat,i,j-1,m,n,dir);
      }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(auto &it : walls){
          ans[it[0]][it[1]]=2;
        }
        for(auto &it : guards){
           ans[it[0]][it[1]]=1;
        }
         // dfs in each of 4 directions
          for(int i=0;i<guards.size();i++){
              int x=guards[i][0];
              int y=guards[i][1];
              dfs(ans,x+1,y,m,n,1);
              dfs(ans,x,y+1,m,n,2);
              dfs(ans,x-1,y,m,n,3);
              dfs(ans,x,y-1,m,n,4);
          }
        long long int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};

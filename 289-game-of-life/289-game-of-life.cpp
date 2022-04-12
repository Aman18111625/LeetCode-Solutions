class Solution {
public:
    void gameOfLife(vector<vector<int>>&mat) {
        if(mat.empty()) return ;
        int n=mat.size();
        int m=mat[0].size();
         int dir[8][2]={{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,1},{-1,-1},{-1,0}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {     
                 int count=0;//store number of 1's
                for(int k=0;k<8;k++)
                {
                    int nx=i+dir[k][0];
                    int ny=j+dir[k][1];
                    if(nx<0 or nx>=n or ny<0 or ny>=m) continue;
                    if(mat[nx][ny]&1) count++;
                }
                if(mat[i][j]==0)
                {
                    if(count==3) mat[i][j]=2;
                }else if(mat[i][j]==1)
                {
                    if(count<2 or count>3) mat[i][j]=1;
                    else mat[i][j]=3;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                 mat[i][j]>>=1;
        }  
    }
};
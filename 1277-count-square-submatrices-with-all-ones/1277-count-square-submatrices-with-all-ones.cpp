class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        if(row==1 and col==1) return mat[0][0];
        int ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
            if(i > 0 && j > 0 && mat[i][j]>0)
              mat[i][j] = min(mat[i-1][j-1], min(mat[i-1][j], mat[i][j-1])) + 1;
                ans+=mat[i][j];
            }
        }
        return ans;
    }
};
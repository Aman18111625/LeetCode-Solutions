class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum_x=0,sum_y=0;
        int n=mat.size();
        for(int i=0;i<n;i++){
            sum_x+=mat[i][i];
            sum_y+=mat[i][n-i-1];
        }
        if(n%2) return sum_x+sum_y-mat[n/2][n/2];//remove the central elements because we count it twixe
       return sum_x+sum_y;
    }
};
class Solution {
public:
  /*
  //TimeC:=>O(N*M*log(N))
  //SC:=>O(N*M)(using extra space as temp matrix)
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        if(n==1 && m==1) return mat[0][0];
        vector<vector<int>>temp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(mat[i][j]){
              temp[i][j]=mat[i][j]+(i>0?temp[i-1][j]:0);
            }
          }
        }
        int ans=0;
        for(auto &it : temp){
          sort(rbegin(it),rend(it));
          int width=1;
          for(auto &h: it){
            ans=max(ans,h*(width));
            width++;
          }
        }
      return ans;
    }*/
  //Approach-2 Using without extra-space
  //TC:=>O(N*M*Log(N))
  int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans=0;
        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j])
                    matrix[i][j] += matrix[i-1][j];
            }
        }
        
        for(int i=0; i<n; i++) {
            sort(matrix[i].begin(), matrix[i].end(), greater());
            for(int j=0; j<m; j++) {
                ans = max(ans, (j+1) * matrix[i][j]);
            }
        }
        return ans;
    }
};
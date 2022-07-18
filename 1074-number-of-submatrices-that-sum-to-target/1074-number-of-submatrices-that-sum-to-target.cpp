class Solution {
public:
    //TC:=>O(N*M)+O(N*M^2)
    //SC:=>O(1)
    //simple calculate prefix sum & then find target in that using a hashmap
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int row=mat.size(),col=mat[0].size();
        if(row==0) return 0;
        //calculate prefix sum
        for(int i=0;i<row;i++){
          for(int j=1;j<col;j++){
            mat[i][j]+=mat[i][j-1];
          }
        }
        int ans=0,sum;
        for(int i=0;i<col;i++){
          for(int j=i;j<col;j++){
            unordered_map<int,int>map;
            map[0]=1;
            sum=0;
            for(int k=0;k<row;k++){
              sum+=mat[k][j]-(i>0?mat[k][i-1]:0);
              ans+=(map.find(sum-target)!=map.end())?map[sum-target]:0;
              map[sum]++;
            }
          }
        }
      return ans;
    }
};

   
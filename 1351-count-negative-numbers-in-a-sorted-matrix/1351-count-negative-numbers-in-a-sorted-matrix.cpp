class Solution {
public:
    // Naive Approach->Simple iterate throught whole matrix and count negative numbers
    // TC:=>O(M*N)
    // SC:=>O(1)
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(grid[i][j]<0) cnt++;
          }
        }
        return cnt;
     }
    //Better Approach->Using Binary Search->count row wise how many negatives
    //TC:=>O(MLogN)
//     //SC:=>O(1)
//    int helper(vector<int>&grid){
//      int low=0,high=grid.size()-1;
//      while(low<=high){
//        int mid=(low+high)/2;
//        if(grid[mid]<0){
//          high=mid-1;
//        }else{
//          low=mid+1;
//        }
//      }
//      return grid.size()-high-1;
//    }
  
//    int countNegatives(vector<vector<int>>& grid) {
//         int m=grid.size(),n=grid[0].size();
//         int cnt=0;
//         for(int i=0;i<m;i++){
//           cnt+=helper(grid[i]);
//         }
//        return cnt;
//     }
};


class Solution {
public:
  //Brute-Force Approach
  //Time-complexity:=>O(M*N)
  //Space-Complexity:=>O(1)
  //Simply traverse in whole matrix and search for target value,if found->true else false
   // bool searchMatrix(vector<vector<int>>&mat, int target){
   //   int n=mat.size(),m=mat[0].size();
   //   for(int i=0;i<n;i++){
   //     for(int j=0;j<m;j++){
   //       if(mat[i][j]==target) return true;
   //     }
   //   }
   //   return false;
   // }
  //Optimal Approach Using Binary Search
  //We know that whenever we have given a sorted thing then first we need to think about binary Search Approach
  //Here we have given that each row is sorted and first element of each row is greater than prev row 
  //so simply we'll check in which row our target lies and then we'll simply apply binary search in that row
  //Time-Complexity=>O(nlogm)
  //Space-Complexity:=>O(1)
     bool binarySearch(vector<int>&arr, int target) {
        int low = 0, high = arr.size();
        while (low <= high){
            int mid = (low + high) / 2;
            if (arr[mid] == target) return true;//found
            else if (arr[mid] < target)//not exist in left search space
                low = mid + 1;
            else//not exist in right search space
                high = mid - 1;
        }
       //not found
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        //base case
        if(mat.empty()) return false;
        int row = 0;
        int n=mat.size(),m=mat[0].size();
        while ((row < mat.size()) && (mat[row].back() < target))
            row++;
        
        if (row >= mat.size()) return false;
        
        return binarySearch(mat[row], target);
    }
};
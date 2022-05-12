class Solution {
    void printAllCombinations(vector<int>&nums,vector<vector<int>>&res,int start,int end){
     if(start==end){
      res.push_back(nums) ;
         return ;
     }  
     int i,k;
     for(i=start;i<=end;i++){
       for(k=start;k<i;k++){
        if(nums[i]==nums[k]) break;
       }
      if(k<i) continue; 
      swap(nums[start],nums[i]);
      printAllCombinations(nums,res,start+1,end);
      swap(nums[start],nums[i]); //backtrack
     }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
      printAllCombinations(nums,ans,0,n-1);
        return ans;
    }
};
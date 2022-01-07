class Solution {
public:
    void printAllCombinations(vector<int>&nums,vector<vector<int>>&v,int start,int end)
    {
     if(start==end)
     {
      v.push_back(nums);
      return ;
     }  
     for(int i=start;i<=end;i++)
     {
      swap(nums[start],nums[i]);
      printAllCombinations(nums,v,start+1,end);
     swap(nums[start],nums[i]);
     }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>v;
        printAllCombinations(nums,v,0,nums.size()-1);
        return v;
    }
};
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
      /*Brute Force
        vector<int>odd,even;
        for(auto num : nums) {
          if(num%2)odd.push_back(num);
          else even.push_back(num);
        }
         
        int i=0,n=nums.size();
        for(auto it : even) nums[i++]=it;
        for(auto it : odd) nums[i++]=it;
        
        return nums;*/
       int j=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
         if(nums[i]%2==0){
           swap(nums[i],nums[j]);
           j++;
         }
       }
        return nums;
    }
};
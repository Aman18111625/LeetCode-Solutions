class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>odd,even;
        for(auto num : nums) {
          if(num%2)odd.push_back(num);
          else even.push_back(num);
        }
         
        int i=0,n=nums.size();
        for(auto it : even) nums[i++]=it;
        for(auto it : odd) nums[i++]=it;
        
        return nums;
    }
};
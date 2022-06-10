class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res(nums.size(),1);
        vector<int>right(nums.size(),1);
        //1.right product
        int prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
         prod*=nums[i];
         right[i]=prod;
        }
        //2.result product
        prod=1;
        for(int i=0;i<nums.size()-1;i++)
        {
        int lp=prod;
        int rp=right[i+1];
        res[i]=(lp*rp);
        prod*=nums[i];
        }
        res[nums.size()-1]=prod;
        return res; 
    }
};
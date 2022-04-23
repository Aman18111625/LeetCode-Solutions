class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int k,l;
        for(k=n-2;k>=0;k--)
        {
          //1.find ind1 from back such a[i]<a[i+1]
        if(nums[k]<nums[k+1]) break; 
        }
        //if permutation is like 3,2,1 . this is last permutation of 1,2,3 so next greater is not possible so we'll return reverse of it.
        if(k<0)
        {
          reverse(nums.begin(),nums.end());//edge-case
        }
        else
        {
          //2.find ind2 from back such a[ind2]>a[ind1]
           for(l=n-1;l>k;l--){
            if(nums[l]>nums[k]) break;
           }
          //3.swap a[ind1],a[ind2]
            swap(nums[k],nums[l]);
          //4. reverse all after ind1 because we have to return next greater so rank will be lesser as much as possible
            reverse(nums.begin()+k+1,nums.end());
       }
    }
};
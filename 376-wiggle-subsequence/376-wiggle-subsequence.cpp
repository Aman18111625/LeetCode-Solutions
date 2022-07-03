class Solution {
public:
    //TC:=>O(N^2)
    //SC:=>O(2*N)
    // int wiggleMaxLength(vector<int>& nums) {
    //     int n=nums.size();
    //     if(n<=1) return 1;
    //     vector<int>first(n,1),second(n,1);
    //     for(int i=1;i<n;i++)
    //     {
    //         for(int j=0;j<i;j++)
    //         {
    //           if(nums[j]<nums[i])
    //           {
    //               first[i]=max(first[i],second[j]+1);
    //           }else if(nums[j]>nums[i])
    //           {
    //               second[i]=max(second[i],first[j]+1); 
    //           }
    //         }
    //     }
    //     return max(first.back(),second.back());
    // }
     
     //TC:=>O(N)
     //SC:=>O(1)
     int wiggleMaxLength(vector<int>& nums){
        int n=nums.size();
        if(n<=1) return n;
        int first=1,second=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i]) first=second+1;
            else if(nums[i-1]>nums[i]) second=first+1;
        }
        return max(first,second);
    }
};
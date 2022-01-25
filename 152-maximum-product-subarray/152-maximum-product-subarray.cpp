class Solution {
public:
  /*Brute-Force : TC=>O(N^2) SC=>O(1)
  we're generating all the subarray here and find maximum of them 
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i=0;i<n;i++)
        {
          int prod=nums[i];
          maxi=max(maxi,prod);
          for(int j=i+1;j<n;j++)
          {
            prod*=nums[j];
            maxi=max(maxi,prod);
          }
        }
      return maxi;
    }*/
  //Optimal Solution:
  //TC:->O(N) SC:->O(1)
  /*
  thought process:->
  first of all we'll traverse from left to right ,that'll give us maximum of left t0 right direction. Now we'll do same for right to left direction .In traverse if we'll get prod==0 then we'll set prod=1 because 0*any would become zero. 

    int maxProduct(vector<int>& nums){
       int n=nums.size(),prod=1,maxi=INT_MIN;
      for(int i=0;i<n;i++)
      {
        if(prod==0) prod=1;
        prod*=nums[i];
        maxi=max(maxi,prod);
      }
      prod=1;
      for(int i=n-1;i>=0;i--)
      {
        if(prod==0) prod=1;
        prod*=nums[i];
        maxi=max(maxi,prod);
      }
       return maxi;
    }*/
  //TC:=O(N) SC:=>O(1)
  /*
  prod1=store maximum prod till current element
  prod2=store minimum prod till current element
  result =store max product of all of subarray
  */
  int maxProduct(vector<int>&nums)
  {
     int prod1 = nums[0],prod2 = nums[0],result = nums[0],n=nums.size();
     for(int i=1;i<n;i++)
     {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp; 
        result = max(result,prod1);
     }  
   return result;
  }
};

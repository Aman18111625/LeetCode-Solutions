class Solution {
public:
  /*
  //Brute Force :->
  //Check for all the possible way 
  //Time Complexity:=>O(N^4)
  //Space-Complexity:=>O(1)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt=0;
        int n1=nums1.size(),n2=nums2.size(),n3=nums3.size(),n4=nums4.size();
       for(int i=0;i<n1;i++)
       {
         for(int j=0;j<n2;j++)
         {
           for(int k=0;k<n3;k++)
           {
             for(int l=0;l<n4;l++)
             {
               if(nums1[i]+nums2[j]+nums3[k]+nums4[l]==0) cnt++;
             }
           }
         }
       }
      return cnt;
    }*/
  
  //Approach-2 Using hashmap
  //a+b+c+d==0 then a+b=-(c+d)
//inserted nums1+nums2 in the hashmap then find -(nums3+nums4) if able to find then add in the result
  //Time-Complexity :=>O(N^2)
  //Space-Complexityh: =>O(N)
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4){
         int cnt=0;
        int n1=nums1.size(),n2=nums2.size(),n3=nums3.size(),n4=nums4.size();
       unordered_map<int,int>mpp;
          for(int i=0;i<n1;i++)
          {
            for(int j=0;j<n2;j++)
            {
              mpp[nums1[i]+nums2[j]]++;
            }
          }
            for(int i=0;i<n3;i++)
            {
              for(int j=0;j<n4;j++)
              {
                int curr=(-1)*(nums3[i]+nums4[j]);
                if(mpp[curr]) cnt+=mpp[curr];
              }
            }
  return cnt;
     }
};
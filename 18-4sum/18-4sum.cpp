class Solution {
public:
  /*
  //Approach-1 
  //Time Complexity :=>O(N^4)
  //Space Complexity :=>O(1)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        if(nums.empty()) return res;
        int sum,rem,n=nums.size();
        sort(nums.begin(),nums.end());
       for(int i=0;i<n-3;i++)
       {
         if(i>0 && nums[i]==nums[i-1]) continue;///skip the duplicate values
         for(int j=i+1;j<n-2;j++)
         {
            if(j>i+1 && nums[j]==nums[j-1]) //skip the duplicate values
                continue;
           for(int k=j+1;k<n-1;k++)
           {
              if(k>j+1 and nums[k]==nums[k-1]) // skip the duplicate value
                  continue;
             rem=target-nums[i]-nums[j];
             for(int l=k+1;l<n;l++)
             {
                if(l>k+1 and nums[l]==nums[l-1])//skip the duplicate values
                  continue;
               int sum=nums[l]+nums[k];
               if(sum>rem) break;
               else if(sum==rem)
               {
                  vector<int>temp(4,0);
                   temp[0]=nums[i];
                   temp[1]=nums[j];
                   temp[2]=nums[k];
                   temp[3]=nums[l];
                 res.push_back(temp);
               }
             }
           }
         }
       }
      return res;
    }*/
  
  //Approach-2 
  //Time-Complexity:=>O(N^3)(three for loop)+O(NLOGN)(sorting)
  //Space-Complexity:=>O(1)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        if(nums.empty()) return res;
        int n=nums.size();
        sort(nums.begin(),nums.end());//it'll help us to skip duplicates
        for(int i=0;i<n-3;i++)
        {
          for(int j=i+1;j<n-2;j++)
          {
             int target_2=target-nums[i]-nums[j];
              int front =j+1;
              int back=n-1;
              while(front<back)
              {
                  int two_sum=nums[front]+nums[back];
                  if(two_sum<target_2) front++;
                  else if(two_sum>target_2) back--;
                  else//we find our group of 4 number whose sum equal to target
                  {
                      vector<int>quadruplets(4,0);
                      quadruplets[0]=nums[i];
                      quadruplets[1]=nums[j];
                      quadruplets[2]=nums[front];
                     quadruplets[3]=nums[back];
                      res.push_back(quadruplets);
                  //number 3
               while(front<back && nums[front]==quadruplets[2]) ++front;
                  //number 4
               while(front<back && nums[back]==quadruplets[3]) --back;
              }
          }
        //number2
            while(j+1<n && nums[j+1]==nums[j]) ++j;
        }
     //number1
        while(i+1<n && nums[i+1]==nums[i]) ++i;
    }
        return res;
    }
};

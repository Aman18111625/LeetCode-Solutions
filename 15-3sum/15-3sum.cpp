class Solution {
public:
    //Brute-Force Approach->running 3 for loops
    //TC:=>O(N^3)
    //SC:=>O(N)(using set for checking duplicats)
    //Give TLE
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     vector<vector<int>>ans;
    //     int n=nums.size();
    //     if(n<3) return ans;
    //     set<vector<int>>st;
    //     for(int i=0;i<=n-3;i++){
    //       for(int j=i+1;j<=n-2;j++){
    //         for(int k=j+1;k<n;k++){
    //           if(nums[i]+nums[j]+nums[k]==0){
    //              vector<int>temp={nums[i],nums[j],nums[k]};
    //              sort(begin(temp),end(temp));
    //              st.insert(temp);
    //           }
    //         }
    //       }
    //     }
    //     for(auto it : st){
    //       ans.push_back(it);
    //     }
    //     return ans;
    // }
    //Optimal Approach ->Using two pointer
    //TC:=>O(N^2)
    //SC:=>O(1)
   vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>>v;
         int n=nums.size();
         if(n<3) return v;
        sort(nums.begin(), nums.end());//sorting will help us to apply two pointer
        for(int i=0; i<n && nums[i]<=0; i++){//if nums[i]>0 then sum of pos number can never be zero.
            if (nums[i] > 0) break;//nums[i]>0 then defenitely nums[low]>0 & nums[high]>0
            if(i>0 && nums[i] == nums[i-1])//skip duplicates
                continue;
            int low=i+1, high=n-1;
            while(low<high){
                int sum = nums[i] + nums[low] + nums[high];
                if(sum > 0) high--;
                else if(sum < 0)low++;
                else{
                  v.push_back({nums[i], nums[low], nums[high]});
                  while (low<high && nums[low]==nums[low+1])low++;//to remove duplicate
                  while (low<high && nums[high]==nums[high-1])high--;//to remove duplicate
                  low++;
                  high--;
                }
            }
        }
        return v;
   }
};

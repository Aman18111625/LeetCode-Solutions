class Solution {
public:
  //Approach-1 Using Hashmap
  //TC=>O(N)
  //SC=>O(N)
  //   vector<int> majorityElement(vector<int>& nums) {
  //      int k=nums.size()/3;
  //       vector<int> vec;
  //       unordered_map<int,int> map;
  //       for(int i=0;i<nums.size();i++) map[nums[i]]++;
  //       for(auto i: map) if(i.second>k) vec.push_back(i.first);
  //       return vec;
  // }
   vector<int> majorityElement(vector<int>& nums) {
     int num1=-1,num2=-1;
     int cnt1=0,cnt2=0;
     int n=nums.size();
     for(auto &num : nums){
       if(num==num1) cnt1++;
       else if(num==num2) cnt2++;
       else if(cnt1==0){
         num1=num;
         cnt1=1;
       } 
       else if(cnt2==0) {
         num2=num;
         cnt2=1;
       }
       else {
         cnt1--;
         cnt2--;
       }
     }
     vector<int>ans;
     cnt1=0,cnt2=0;
     for(auto &num : nums){
       if(num==num1) cnt1++;
       else if(num==num2) cnt2++;
     }
     if(cnt1>n/3) ans.push_back(num1);
     if(cnt2>n/3) ans.push_back(num2);
     return ans;
   }
};
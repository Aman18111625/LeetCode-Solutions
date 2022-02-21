class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mpp;
        for(auto &num: nums) mpp[num]++;
        int n=nums.size()/2;
        for(auto &it : mpp){
          if(it.second>n) return it.first;
        }
      return -1;
    }
};
class Solution {
public:
    int arraySign(vector<int>& nums) {
      int cnt0=0,cntNeg=0;
      for(auto &it : nums){
        if(it==0) return 0;
        else if(it<0) cntNeg++;
      }
      return (cntNeg&1)?-1:1;
    }
};
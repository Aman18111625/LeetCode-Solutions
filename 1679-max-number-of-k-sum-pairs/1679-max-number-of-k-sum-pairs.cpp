class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int cnt=0;
        int i=0,j=n-1;
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum==k) {
              i++,j--;
              cnt++;
            }else  if(sum>k) j--;
            else i++;
        }
        return cnt;
    }
};
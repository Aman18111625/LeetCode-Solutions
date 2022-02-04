class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0;
        for(int i=0;i<k;i++) sum+=nums[i];
        double maxi=sum/k;
        for(int i=k;i<n;i++)
        {
          sum+=nums[i];
          sum-=nums[i-k];
          if(sum/k>maxi) maxi=sum/k;
        }
        return maxi;
    }
};
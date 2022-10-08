class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int closestSum,flag=0;
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--){
            int low=0,high=i-1;
            int sum=0;
            while(low<high){
                sum=nums[low]+nums[i]+nums[high];
                if(sum==target) return target;
                if(sum<target) low++;
                else high--;
                if(flag==0){
                 closestSum=sum;
                 flag=1;
                }
                else{
                 if(abs(target-sum)< abs(target-closestSum)) closestSum=sum;
                }
            }
        }
        return closestSum;
      
    }
};
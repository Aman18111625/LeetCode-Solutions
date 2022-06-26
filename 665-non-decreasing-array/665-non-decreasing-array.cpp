class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
       int count = 0, mini = INT_MIN;
        for(int i = 0; i < n-1; i++){
            if(nums[i] <= nums[i+1]){
                mini = nums[i];
            }
            else{
                if(nums[i+1] < mini)nums[i+1] = nums[i];
                count++;
                if(count > 1)return false;
            }
        }
        return true;
    }
};
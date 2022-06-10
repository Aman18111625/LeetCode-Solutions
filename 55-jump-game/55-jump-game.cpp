class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, minjump = 0,n=nums.size();
        for(i = n-2; i >= 0; i--){
            minjump++;
            if(nums[i] >= minjump)
			        minjump = 0;
        }
        if(minjump == 0) return true;
        else return false;
    }
};
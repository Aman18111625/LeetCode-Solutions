class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
         int n=nums.size();
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<target) cnt1++;
            if(nums[i]==target) cnt2++;
        }
        vector<int>ans;
        while(cnt2--)
        {
            ans.push_back(cnt1++);
        }
        return ans;
    }
};
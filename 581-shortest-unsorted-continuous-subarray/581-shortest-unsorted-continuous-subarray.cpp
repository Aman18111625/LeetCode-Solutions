class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>arr(nums.begin(),nums.end());
        sort(arr.begin(),arr.end());
        int n=nums.size();
        int i=0,j=n-1;
        while(i<n && nums[i]==arr[i]) i++;
        while(j>=0 && nums[j]==arr[j]) j--;
        if(i<j) return (j-i+1);
        return 0;
    }
};
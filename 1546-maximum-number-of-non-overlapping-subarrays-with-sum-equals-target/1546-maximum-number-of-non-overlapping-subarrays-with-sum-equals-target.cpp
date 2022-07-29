class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int res = 0, endIndex = -1, sum = 0,n=nums.size();
        unordered_map<int,int> map;
        map[0] = 0;
        for(int i = 1; i <= n; i++){
            sum += nums[i - 1];
            if(map.count(sum - target)){
                int index = map[sum - target];
                if(index >= endIndex){
                    res++;
                    endIndex = i;
                }
            }
            map[sum] = i;
        }
        return res;
    }
};
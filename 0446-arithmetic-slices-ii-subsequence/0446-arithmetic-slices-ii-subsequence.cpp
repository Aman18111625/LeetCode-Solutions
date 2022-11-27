class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<long,long>>dp(n);//{key:index,value:diff}
        int res = 0;
        for (int i = 1; i < n; i++){
            for(int j=i-1;j>=0;j--){
                long diff=(long)nums[i]-(long)nums[j];
                dp[i][diff]++;
                if(dp[j].find(diff)!=dp[j].end()){
                    dp[i][diff]+=dp[j][diff];
                    res+=dp[j][diff];
                }
            }
        }
        return res; 
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
      
	// vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
	// for(int ind=n-1;ind>=0;ind--){
	// 	for(int buy=0;buy<=1;buy++){
	// 		for(int cap=1;cap<=2;cap++){//for cap=0 already 0
	// 			if(buy==1){
	// 				dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
	// 			}else{
	// 				dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
	// 			}
	// 		}
	// 	}
	// }
	// return dp[0][1][2];
    vector<vector<int>>after(2,vector<int>(3,0));
	  vector<vector<int>>curr(2,vector<int>(3,0));
	  for(int ind=n-1;ind>=0;ind--){
		for(int buy=0;buy<=1;buy++){
			for(int cap=1;cap<=2;cap++){//for cap=0 already 0
				if(buy==1){
					curr[buy][cap]=max(-prices[ind]+after[0][cap],after[1][cap]);
				}else{
					curr[buy][cap]=max(prices[ind]+after[1][cap-1],after[0][cap]);
				}
			}
		}
	 	 after=curr;
	 }
	return after[1][2];
}
};
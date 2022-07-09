class Solution {
public:
    //TLE
    //TC:=>O(N^K) && SC:=>O(N)
    // int maxResult(vector<int>& nums, int k,int i=0) {
    //     int n=nums.size();
    //     if(i>=n-1) return nums.back();
    //   	int score = INT_MIN;
    // for(int j = 1; j <= k; j++) 
    // score = max(score, nums[i] + maxResult(nums, k, i + j));
    // return score;
    // }

//TC:=>O(N*K)
//SC:=>O(N)
// recursive solver which finds max score to reach n-1 starting from ith index
// int solve(vector<int>& nums, vector<int>& dp, int k, int i) {
// 	if(dp[i] != INT_MIN) return dp[i];   // already calculated result for index i
// 	for(int j = 1; j <= k; j++)          // try jumps of all length and choose the one which maximises the score
// 		if(i + j < size(nums))
// 			dp[i] = max(dp[i], nums[i] + solve(nums, dp, k, i + j));
  
//    return dp[i];
// }
  
//   int maxResult(vector<int>& nums, int k) {
// 	    vector<int> dp(size(nums), INT_MIN);
// 	    dp.back() = nums.back();  // dp[n-1]=nums[n-1]
// 	    return solve(nums, dp, k, 0);
//   }
  
  //TC:=>O(N*K)
  //SC:=>O(N)
//   int maxResult(vector<int>& nums, int k) {
// 	  vector<int> dp(size(nums), INT_MIN);
//    	dp[0] = nums[0];
// 	for(int i = 1; i < size(nums); i++) 
// 		for(int j = 1; j <= k && i - j >= 0; j++)      // try all jumps length
// 		  	dp[i] = max(dp[i], dp[i - j] + nums[i]);   // choose the jump from previous index which maximises score       
// 	return dp.back();
// }
  
  //TC:=>O(N)
  //SC:=>O(N)
  int maxResult(vector<int>& nums, int k) {
	  vector<int> dp(size(nums));
   	dp[0] = nums[0];
	  deque<int> q{ 0 };
	 for(int i = 1; i < size(nums); i++) {
	 	if(q.front() < i - k) q.pop_front();//can't reach current index from index stored in q 
		dp[i] = nums[i] + dp[q.front()];// update max score for current index
		while(!q.empty() && dp[q.back()] <= dp[i])//pop indices which won't be ever chosen in the future
		q.pop_back();
		q.push_back(i);// insert current index
	 }
	 return dp.back();
  }
  
};



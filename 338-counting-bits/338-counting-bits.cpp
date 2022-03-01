class Solution {
  /*TC:=>O(NLOGN)
  int countSetBit(int n){
    int cnt=0;
    while(n){
      if(n&1) cnt++;
      n>>=1;
    }
    return cnt;
  }
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
          ans.push_back(countSetBit(i));
        }
      return ans;
    }*/
  public:
  //TC:->O(N)
  vector<int> countBits(int n){
    vector<int>dp(n+1);
    dp[0]=0;//number of 1's in 0 is 0
    for(int i=1;i<=n;i++){
      dp[i]=dp[i/2]+i%2;
    }
    return dp;
  }
};
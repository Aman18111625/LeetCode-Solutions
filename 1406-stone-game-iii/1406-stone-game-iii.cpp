class Solution {
  int dp[50001];
  int helper(int i,vector<int>&stones,int &size)
  {
    if(i>=size) return 0;//out of bound
    //Now we have three option ->we can pick 1,2 or 3 from the remaining stones 
    if(dp[i]!=-1) return dp[i];//if already calculate
    int ans=INT_MIN;
    ans=max(ans,stones[i]-helper(i+1,stones,size));//alice picked only 1(ith) then bob will be picked from (i+1)th
    if(i+1<size)
       ans=max(ans,stones[i]+stones[i+1]-helper(i+2,stones,size));//alice picked only first 2(ith,i+1) then bob will be picked from (i+2)th
    if(i+2<size)
       ans=max(ans,stones[i]+stones[i+1]+stones[i+2]-helper(i+3,stones,size));//alice picked 3(ith,i+1,i+2) then bob will be picked from (i+3)

    return dp[i]=ans;
  }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int size=stoneValue.size();
        memset(dp,-1,sizeof(dp));
        int ans=helper(0,stoneValue,size) ;//this ftn will return us difference of alice and bob;
      if(ans==0) return "Tie"; //both get equal stones
      return ans>0?"Alice":"Bob";
    }
};
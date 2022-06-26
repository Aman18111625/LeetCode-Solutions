class Solution {
  public:
//Recursive+ Memoization
//TC:=>O(N^2)
//SC:=>O(N)+O(N)(stack-space)
//   int dp[2001][2001];
//   bool helper(vector<int>&stones,int start,int jump)
//   {
//     if(start==stones.size()-1) return true;//we reach the (n-1)th position
//     if(dp[start][jump]!=-1) return dp[start][jump];
//     bool flag=false;
//     int curr=stones[start];
//     for(int i=start+1;i<stones.size() && !flag;i++)
//     {
//       int need=stones[i]-curr;
//       if(need-jump>1) break;
//       else if(need-jump>=-1 && need-jump<=1)
//       {
//         flag=helper(stones,i,need);
//       }
//     }
//     return dp[start][jump]=flag;
//   }
  
//   bool canCross(vector<int>& stones) {
//       int n=stones.size();
//       if(n==2) return stones[1]<=1;
//       memset(dp,-1,sizeof(dp));
//       return helper(stones,0,0);
//     }
  
  //Recursive+Moization +Binary Search
  //TC:=>O(NLOGN)
  //SC:=>O(N)+O(N)(stack-space)
  int dp[2001][2001];
  bool find(vector<int> &stones, int i,int k){
  	//we reached the ith stone with k jumps 
    //Base Cases
    if(i==stones.size()-1) return true;
    if(i>=stones.size())  return false;
  	//if we already encountered this state ,we'll simply return it
    if(dp[i][k]!=-1)  return dp[i][k]; 	
    bool res = false;
  	// from here we can either go to k-1 , k , k +1 th stone 
    for(int j=-1;j<=1;j++){
        int next_jump=k+j;
        if(next_jump>0){
  		  //now the next stone would be = currstone + jump
  		  //using binary search to find the index of next stone if it exists
           int in= lower_bound(stones.begin(),stones.end(),stones[i]+next_jump)-stones.begin();
           if(in == stones.size() || stones[in]!=stones[i]+next_jump) // checking existence of next_stone in array
                  continue;
  			//if next stone exists then we will move to that index (in) with the jump that we took
              res=res||find(stones,in,next_jump);
          }
      }
  	
      return dp[i][k]=res;
      
  }
  
   bool canCross(vector<int>& stones) {
      memset(dp,-1,sizeof(dp)); 
      return find(stones, 0,0);
  }
};

 
    
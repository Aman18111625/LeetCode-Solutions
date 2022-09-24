class Solution {
public:
      //Brute-Force Approach
      //Time-complexity:->O(N^2)
      //Space-Complexity:->O(1)
      // int maxProfit(vector<int>& prices){
      //   int ans=INT_MIN;
      //   int n=prices.size();
      //   for(int i=0;i<n;i++){
      //     for(int j=i+1;j<n;j++){
      //       ans=max(ans,prices[j]-prices[i]);
      //     }
      //   }
      //   return ans==INT_MAX?-1:ans;
      // }
    
   //Optimized Approach
   //Time-Complexity:->O(N)
  //Space-Complexity:->O(1)
    int maxProfit(vector<int>& prices) {
         int profit=0,mini=INT_MAX;
         for(auto &it: prices){
           if(it<mini) mini=it;
           else if(it-mini>profit)
             profit=it-mini;
         }
      return profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,mini=INT_MAX;
         for(auto &it: prices)
         {
           if(it<mini) mini=it;
           else if(it-mini>profit)
             profit=it-mini;
         }
      return profit;
    }
};
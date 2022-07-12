class Solution {
public:
  
   bool helper(vector<int>&matchsticks,vector<int>&vis,int target,int currSum,int ind,int subsets){
     if(subsets==1) return true;//if subsets==1 then we found all the subsets
     //we found one subset whose sum is equal to target go on to the next one starting from currSum==0
     if(currSum==target) return helper(matchsticks,vis,target,0,0,subsets-1);
     for(int j=ind;j<matchsticks.size();j++){
//If we visited this index already or currSum+matchsticks[j]>target then we can't use it
       if(vis[j] or currSum+matchsticks[j]>target ) continue;
       vis[j]=true;//mark as visited
       if(helper(matchsticks,vis,target,currSum+matchsticks[j],j+1,subsets)) return true;
       vis[j]=false;//mark as unvisited->backtracking->very important step
     }
     return false;
   }
  
    bool makesquare(vector<int>& matchsticks) {
        int sum=0,n=matchsticks.size();
        for(auto &match : matchsticks) sum+=match;
        if(n<4 or sum%4) return false;
        vector<int>vis(n,false);
      //we have to find subset of sum equal to sum/4
        return helper(matchsticks,vis,sum/4,0,0,4);
    }
};


   
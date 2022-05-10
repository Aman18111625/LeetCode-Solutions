class Solution {
public:
    void findCombinations(int k1,int k,int n,int pos,vector<vector<int>>&ans,vector<int>&ds)
    {
       if(n==0 &&  k1==k){
            ans.push_back(ds);
            return;
        }
        if(k1<=k)
        {
        for(int i=pos;i<=9;i++){
           ds.push_back(i);
           findCombinations(k1+1,k,n-i,i+1,ans,ds);
           ds.pop_back();
          }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombinations(0,k,n,1,ans,ds);
        return ans;
    }
};
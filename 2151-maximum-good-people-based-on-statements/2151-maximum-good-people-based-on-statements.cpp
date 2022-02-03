class Solution {
public:
  //Time-Complexity:=>(2^N(checking all the possible ways) * N^2(check valid or not))
    int res=0,n=0;
    void dfs(vector<vector<int>>&s,string& curr,int idx,int goodPersonCount)
    {
       if(idx==n)
       {
            //Check if cur is valid
         if(isValid(curr,s)) res=max(goodPersonCount,res);
         return ;
       }
      //Make current person a good person and call DFS
      curr.push_back('1');
      dfs(s,curr,idx+1,goodPersonCount+1);
      //Backtrack: Make current person a bad person and call DFS
      curr.back()='0';
      dfs(s,curr,idx+1,goodPersonCount);
      curr.pop_back();
    }
//isValid() will check if the statement of goodPerson (i) about person (j) i.e. statement[i][j], is contradictory to what we have in cur[j]   
//If it is contradictory, then in terms of question i is lying, and is not a goodPerson, so this is not a valid count.
        //If s[i][j] == 2, i.e. person i said nothing about j, then we can skip it.
    bool isValid(string& curr,vector<vector<int>>&s)
    {
      for(int i=0;i<n;i++)
      {
        if(curr[i]=='1')//We only care about what good people say
          //Now we check what they said is in accordance with what we have in cur
        {
          for(int j=0;j<n;j++)
          {
            if(s[i][j]!=2 && s[i][j]!=curr[j]-'0') return false;
          }
        }
      }
      //All statements made by good person is in accordance with cur, so we have a valid count of good people
      return true;
    }
    int maximumGood(vector<vector<int>>& s) {
       n=s.size();
      string curr="";
      dfs(s,curr,0,0);
      return res;
    }
};
   
  
  
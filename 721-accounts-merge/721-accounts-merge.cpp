class Solution {
  //1st hashmap
  //key:name,value: set of email associated with name
  //key:email,value: set of name associated with email
  unordered_map<string,unordered_set<string>>graph;
  //Set ->to keep track of visited or not
  unordered_set<string>visited;
  void dfs(string s, vector<string>&ans){
    ans.push_back(s);
    visited.insert(s);
    for(string str:graph[s]){
        if(visited.find(str)==visited.end())
            dfs(str,ans);
    }
  }

public:
   vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    if(accounts.size()==1){
        return accounts;
    }
    //create graph
    vector<vector<string>>result;
    for(auto &acc : accounts){
       for(int i=1;i<acc.size();i++){
            graph[acc[i]].insert(acc[1]);
            graph[acc[1]].insert(acc[i]);
        }
    }
    for(auto &acc : accounts){
        if(visited.find(acc[1])==visited.end()){
            vector<string> ans;
            dfs(acc[1],ans);
            sort(ans.begin(),ans.end());
            ans.insert(ans.begin(),acc[0]);
            result.push_back(ans);
        }
    }
    return result; 
}
};
class Solution {
public:
    vector<int>vis;//to keep of already visited or not
    vector<vector<int>>graph;//store graph
     void dfs(int ind,vector<int>&index,vector<char>&letters,string &s){
         vis[ind]=true;//mark as visited
         index.push_back(ind);//also store ind into index array
         letters.push_back(s[ind]);//also store char at ind in letters
       //now traverse for all adjacent of ind
        for(auto adj : graph[ind]){
            if(!vis[adj]){
              dfs(adj,index,letters,s);
            }
        }
     }
  
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        vis.resize(n,false);
        graph.resize(n);
        for(auto &it : pairs){
          graph[it[0]].push_back(it[1]);
          graph[it[1]].push_back(it[0]);
        }
        
       for(int i=0;i<n;i++){
           vector<int>index;
           vector<char>letters;
           if(!vis[i]){
             dfs(i,index,letters,s);
           }
           sort(index.begin(),index.end());
           sort(letters.begin(),letters.end());
           int size=index.size();
           for(int j=0;j<size;j++){
             s[index[j]]=letters[j];
           }
       }
       return s;
    }
};
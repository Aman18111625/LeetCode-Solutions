class Solution {
public:
    int findParents(char x,unordered_map<char,char>&parent){
      if(parent[x]!=x) parent[x]=findParents(parent[x],parent);
      return parent[x];
    }
  
    bool equationsPossible(vector<string>& equations) {
      unordered_map<char,char>parent;
      for(auto x: equations){
        parent[x[0]]=x[0];
        parent[x[3]]=x[3];
      }
      
      for(auto eq: equations){
         char x=findParents(eq[0],parent);
         char y=findParents(eq[3],parent);
         if(eq[1]== '=') parent[y]=x;
      }
      for(auto it : equations){
            char x=findParents(it[0],parent);
            char y=findParents(it[3],parent);
            if(it[1]=='!' && x==y) return false;
      }
      return true;
    }
};

      
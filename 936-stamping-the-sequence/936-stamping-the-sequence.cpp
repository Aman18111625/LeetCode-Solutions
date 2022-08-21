class Solution {
public:
  //TC:=>O(N*(N-M)^2)
  //SC:=>O(N)
  int stars,n,m;
  vector<int>ans;
  
  bool helper(string& target, int& start, string& stamp){
	// check for match
	for(int i = 0; i < m; i++)
		if(target[i + start] != '*' && target[i + start] != stamp[i]) return false;
	  ans.push_back(start);
	 for(int i = start; i - start < m; i++) 	
		 stars += (target[i] != '*'), target[i] = '*';        
	
	  return true; // denotes replacement happened at index start to start + m
  }
  
  
  
  
vector<int> movesToStamp(string stamp, string target) {  
    stars=0,n=size(target),m=size(stamp);
    vector<bool>vis(n,false);
    ans.clear();
   while(stars<n){
     bool replaced = false;
     for(int i=0;i<=(n-m) && stars<n ;i++ ){
       if(!vis[i]){
         replaced=helper(target,i,stamp);
         vis[i]=replaced;
       }
     }
     if(!replaced) return {};
   }
    reverse(ans.begin(),ans.end());
    return ans;
 }
};
   

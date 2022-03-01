class Solution {
public:
  /*Approach-1 Using Queue
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        vector<int>ans(n,0);
        queue<int>q;
        for(int i=0;i<n;i++){
          if(s[i]==c) q.push(i);
        }
        int curr=q.front();
         q.pop();
        for(int i=0;i<n;i++){
          if(!q.empty() && abs(curr-i)>=abs(q.front()-i)){
            curr=q.front(); q.pop();
          }
           ans[i]=abs(curr-i);
        }
      return ans;
    }*/
   vector<int> shortestToChar(string s, char c){
     int n=s.size();
     vector<int>ans(n,INT_MAX);
     int p=INT_MAX;
     for(int i=0;i<n;i++){
       if(s[i]==c){
         p=i;
         ans[i]=0;
       }else{
         ans[i]=abs(p-i);
       }
     }
     for(int i=n-1;i>=0;i--){
        if (s[i] == c)
            p = i;
        else
            ans[i] = min(ans[i], abs(p - i));
     }
     return ans;
   }
};
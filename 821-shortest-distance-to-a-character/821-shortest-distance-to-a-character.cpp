class Solution {
public:
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
    }
};
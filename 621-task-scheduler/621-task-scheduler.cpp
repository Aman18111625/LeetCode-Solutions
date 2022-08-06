class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         int mpp[26];
         memset(mpp,0,sizeof(mpp));
         int cnt=0,res=0;
         for(int i=0;i<tasks.size();i++) mpp[tasks[i]-'A']++;
         for(int i=0;i<26;i++)
              cnt=max(cnt,mpp[i]);
        
         for(int i=0;i<26;i++)
             if(mpp[i]==cnt) res++;
        
         return max((int)tasks.size(),(cnt-1)*(n+1)+res);
    }
};
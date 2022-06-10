class Solution {
public:
   bool valid(string st){
       if(st.size()==1 && st[0]!='0') return true;
       else if(st.size()>=2){
         if(st[0]=='1' || (st[0]=='2' && st[1]<='6'))return true; 
        }
        return false;
    }
    
    int numDecodings(string s) {
         int n=s.length();
         int dp[n];
         memset(dp,0,sizeof dp);
         dp[0]=valid(s.substr(0,1))?1:0;
        for(int i=1;i<n;i++){
            if(valid(s.substr(i,1))) dp[i]+=dp[i-1];
            if(valid(s.substr(i-1,2))) {
             dp[i]=dp[i]+(i-2>=0?dp[i-2]:1);  
            }
        }
        return dp[n-1];
    }
};
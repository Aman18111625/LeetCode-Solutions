class Solution {
public:
    int countSubstrings(string s) {
      int n=s.size();
      bool dp[n][n];//it'll store whether a string from i to j is palindrome or not
        int count=0;//store result
        int gap,i,j;
        for(gap=0;gap<n;gap++)
        {
         for(i=0,j=gap;j<n;i++,j++)
         {
          if(gap==0) dp[i][j]=true;//only one char 
            else if(gap==1)//only two char so we'll check they're equal or not
            {
             if(s[i]==s[j]) dp[i][j]=true;
                else dp[i][j]=false;
            }
             else//more than 2 char
             {
              if(s[i]==s[j] && dp[i+1][j-1]==true) dp[i][j]=true;
                 else dp[i][j]=false;
             }
             if(dp[i][j]) count++;
         }   
        }
        return count;
    }
};

         

           
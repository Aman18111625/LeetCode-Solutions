class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>IS;//to store index
        int ans=0;
        int n=s.length();
        IS.push(-1);
        for(int i=0;i<n;i++)
        {
          if(s[i]=='(') //opening ->then push
          {
             IS.push(i);
          }
          else //closing
          { 
            if(IS.top()!=-1 and s[IS.top()]=='(')
            {
              IS.pop();
              ans=max(ans,i-IS.top());
            }
            else{
                IS.push(i);
              }
          }
        }
        return ans;
    }
};
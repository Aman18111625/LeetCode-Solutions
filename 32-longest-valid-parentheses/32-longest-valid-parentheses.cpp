class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char>CS;//to store char
        stack<int>IS;//to store index
        int ans=0;
        int n=s.length();
        IS.push(-1);
        for(int i=0;i<n;i++)
        {
          if(s[i]=='(') //opening ->then push
          {
             CS.push(s[i]);
             IS.push(i);
          }
          else //closing
          { 
            if(!CS.empty() and CS.top()=='(')//pop and find max ans
            {
              CS.pop();
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
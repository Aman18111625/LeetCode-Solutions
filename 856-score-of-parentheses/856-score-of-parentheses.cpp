class Solution {
public:
    int scoreOfParentheses(string s) {
      /*TC:=>O(N) SC:=>O(N)
       stack<int>st;
       st.push(0);// pushing 0 because let's say we have "()" think about it.
       for(auto &it : s)
       {
          // if meets this '(' then just add 0 to stack
         if(it=='(') st.push(0);
         else  
         {
//If we meets ')' then take out the top value, and
//check if its 0 then simply add 1 to the next top of the stack, or
//If its more than 0 it means we are already in one inside the level, then
//Simply multiply that value by 2, and add it into the next top of the stack
            int val=st.top();
            st.pop();
            int newVal=0;
            if(val)
            {
              newVal=2*val;
            }else
            {
             newVal=1;
            }
           st.top()+=newVal;
         }
       }
      return st.top();*/
      int depth=0;
      int ans=0,n=s.size();
      for(int i=0;i<n;i++)
      {
        if(s[i]=='(') depth++;
        else depth--;
        if(i-1>=0 && s[i-1]=='(' && s[i]==')') ans+=(pow(2,depth));
      }
      return ans;
    }
};
   

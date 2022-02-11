class Solution {
public:
    int scoreOfParentheses(string s) {
       stack<int>st;
       st.push(0);
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
      return st.top();
    }
};
   

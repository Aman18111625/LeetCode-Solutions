class Solution {
public:
    int calculate(string s) {
      int res=0;
      int sign=1;
      int i=0,n=s.size();
      stack<int>st;
      
      while(i<n){
        if(s[i]=='+'){//if sign is '+' then sign=1 it's means positive
          sign=1;
        }else if(s[i]=='-'){//negative
          sign=-1;
        }else if(isdigit(s[i])){
          int num=s[i]-'0';
          while(i+1<n && isdigit(s[i+1])){
            num=num*10+(s[i+1]-'0');
            i++;
          }
          res+=num*sign;
        }else if(s[i]=='('){//if '(' then push res and sign and find ')' 
          st.push(res);
          st.push(sign);
          res=0;
          sign=1;
        }else if(s[i]==')'){
                int prev_sign=st.top();
                st.pop();
                int prev_result=st.top();
                st.pop();
          //add the curr result in parenthesis to prev result and update the entire result
                res=res*prev_sign + prev_result;
                //prev_sign will be the sign before the begin of parenthesis
          }
          i++;
      }
      return res;
    }
};
        
      

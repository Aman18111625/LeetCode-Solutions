class Solution {
public:
    int evalRPN(vector<string>& tokens) {
          stack<int>st;
         int n=tokens.size();
        for(int i=0;i<n;i++)
        {
            if(tokens[i].size()>1 or isdigit(tokens[i][0]))
                st.push(stoi(tokens[i]));
            else{
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                switch(tokens[i][0])
                {
                    case '+':{
                        op1+=op2;
                        break;
                    }
                    case '-':{
                       op1-=op2;
                        break;
                    }
                    case '*':{
                        op1 *= op2;
                        break;
                    }
                    case '/':{
                       op1/=op2;
                        break;
                    }
                }
                st.push(op1);
            }
        }
     return st.top();
    }
};
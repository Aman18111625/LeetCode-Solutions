class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]==')')
            {
                if(!st.empty() and s[st.top()]=='(')
                    st.pop();
                else 
                {
                    s.erase(i,1);
                    i--;
                }
            }
            else if(s[i]=='(')
                st.push(i);
        }
        while(!st.empty())
        {
            s.erase(st.top(),1);
            st.pop();
        }
        return s;
    }
};
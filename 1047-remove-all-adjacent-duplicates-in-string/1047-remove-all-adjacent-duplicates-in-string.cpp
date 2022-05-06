class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        if(n <= 1) return s;
        stack<char> st;
        string ans = "";
        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(s[i]);
                ans += s[i];
            } else {
                if(s[i] == st.top()){
                    st.pop();
                    ans.erase(ans.end()-1);
                } else {
                    st.push(s[i]);
                    ans += s[i];
                }
            } 
        }
        return ans;
    }
};
class Solution {
public:
    void reverseString(vector<char>& s) {
        // reverse(s.begin(),s.end());
        stack<char>st;
        for(auto ch: s) st.push(ch);
        string ans="";
        while(!st.empty()){
          ans+=st.top();
          st.pop();
        }
        s.clear();
        for(auto ch: ans) s.push_back(ch);
    }
};
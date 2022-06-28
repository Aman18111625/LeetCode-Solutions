class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,vector<int>>s1;
        unordered_map<char,vector<int>>s2;
        for(int i=0;i<s.length();i++)
        {
            s1[s[i]].push_back(i);
            s2[t[i]].push_back(i);
            if(s1[s[i]]!=s2[t[i]]) return false;
        }
        return true; 
    }
};
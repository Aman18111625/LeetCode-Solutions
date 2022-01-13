class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string rot=s+s;
        rot.pop_back();
        rot=rot.substr(1);
        if(rot.find(s)!=string::npos) return true;
        return false;
    }
};
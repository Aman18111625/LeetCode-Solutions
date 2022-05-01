class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string res1="",res2="";
        for(auto ch : s){
          if(islower(ch)) res1+=ch;
          else if(!res1.empty()) res1.pop_back();
        }
        
        for(auto ch : t){
          if(islower(ch)) res2+=ch;
          else if(!res2.empty()) res2.pop_back();
        }
        return res1==res2;
    }
};
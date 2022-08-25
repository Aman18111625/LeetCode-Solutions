class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length()==1 && magazine.length()==1){
          if(ransomNote[0]==magazine[0]) return true;
          else return false;
        }
        if(ransomNote.length()>magazine.length()) return false;
           map<char,int> m;
        for(int i = 0; i < magazine.size(); i++)
            m[magazine[i]]++;
        for(auto x : ransomNote){
            if(m[x] > 0)
                m[x]--;
            else
                return false;
        }
        return true;
    }
};
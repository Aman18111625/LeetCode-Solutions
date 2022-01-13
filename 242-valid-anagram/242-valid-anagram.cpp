class Solution {
public:
    /*
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }*/
     bool isAnagram(string s, string t)
     {
         if(s.size()!=t.size()) return false;
         unordered_map<char,int>mpp;
         for(auto ch : s) mpp[ch]++;
         for(auto it: t)
         {
             mpp[it]--;
             if(mpp[it]<0) return false;
         }
         return true;
     }
};
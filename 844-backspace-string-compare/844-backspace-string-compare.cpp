class Solution {
public:
    bool backspaceCompare(string s, string t) {
       //Brute-Force 
       //TC:=>O(N) ,SC:=>O(N)
//       string res1="",res2="";
//       for(auto ch : s){
//         if(islower(ch)) res1+=ch;
//         else if(!res1.empty()) res1.pop_back();
//       }

//       for(auto ch : t){
//         if(islower(ch)) res2+=ch;
//         else if(!res2.empty()) res2.pop_back();
//       }
//       return res1==res2;
        int k=0,p=0;
        int n=s.size(),m=t.size();
        for(int i=0;i<n;i++){
          if(s[i]=='#') {
            k--;
            k=max(0,k);
          }else{
            s[k++]=s[i];
          }
        }
        for(int i=0;i<m;i++){
          if(t[i]=='#') {
            p--;
            p=max(0,p);
          }else{
            t[p++]=t[i];
          }
        }
       if(k!=p) return false;
       else{
         for(int i=0;i<k;i++) if(s[i]!=t[i]) return false;
       }
        return true;
    }
};
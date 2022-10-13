class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string ans="11";
        for(int i=3;i<=n;i++){
          string temp="";
          ans+='#';//this will help us identify segment
          int cnt=1;
          for(int j=1;j<ans.size();j++){
             if(ans[j]==ans[j-1]) cnt++;//if equal then increment count
             else{//not equal then add cnt and then number
             temp+=to_string(cnt);
             temp+=ans[j-1];
             cnt=1;//reset count as 1 because now we have to check other segments
           }     
          }
          ans=temp;
        }
        return ans;
    }
};

 
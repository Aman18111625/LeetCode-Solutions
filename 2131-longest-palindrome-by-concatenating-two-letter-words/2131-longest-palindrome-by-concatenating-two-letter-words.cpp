class Solution {
public:
    int longestPalindrome(vector<string>& words) {
       unordered_map<string,int>map;
       for(auto word: words){
         map[word]++;
       }
       bool middle=false;
       int ans=0;
       for(auto &it: map){
         string word=it.first;
         int cnt=it.second;
         string rev=word;
         reverse(rev.begin(),rev.end());
         if(word!=rev){
           if(map.find(rev)!=map.end()){
             ans+=min(map[word],map[rev]);
           }
         }else{
            ans+=cnt;
            if(cnt&1) {
              middle=true;
              ans-=1;
            }
         }
       }  
       ans+=middle;
       return ans*=2;  
    }
};
  
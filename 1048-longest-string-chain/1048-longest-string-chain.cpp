class Solution {
   static bool comp(string &a,string &b){
     return a.size()<b.size();
   }
public:
    int longestStrChain(vector<string>& w) {
       int n=w.size();
       int maxLength=0;
       sort(begin(w),end(w),comp);//sort according to the size of strings
       map<string,int>mpp;//to store length of longest possible word chaing for string
       for(string word : w){
         int longest=0;
         for(int i=0;i<word.size();i++){
           string sub=word.substr(0,i)+word.substr(i+1,word.size());
           longest=max(longest,mpp[sub]+1);
         }
         mpp[word]=longest;
         maxLength=max(maxLength,longest);
       }
      return maxLength;
    }
};


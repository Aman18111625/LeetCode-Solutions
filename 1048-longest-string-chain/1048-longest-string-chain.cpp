class Solution {
  public:
//Approach-1:->Simple check for all the substring of a string 
   static bool comp(string &a,string &b){
     return a.size()<b.size();
   }

//     int longestStrChain(vector<string>& w) {
//        int n=w.size();
//        int maxLength=0;
//        sort(begin(w),end(w),comp);//sort according to the size of strings
//        map<string,int>mpp;//to store length of longest possible word chaing for string
//        for(string word : w){
//          int longest=0;
//          for(int i=0;i<word.size();i++){
//            string sub=word.substr(0,i)+word.substr(i+1,word.size());
//            longest=max(longest,mpp[sub]+1);
//          }
//          mpp[word]=longest;
//          maxLength=max(maxLength,longest);
//        }
//       return maxLength;
//     }
  
  //TC:=>O(N^3)
  //SC:=>O(N)
  bool checkPossible(string& a,string& b){
    if(a.size()!=b.size()+1) return false;
    int first=0,second=0;
    while(first<a.size()){
      if(a[first]==b[second]){
        first++;
        second++;
      }else{
        first++;
      }
    }
    return first==a.size() && second==b.size();
  }
  
  int longestStrChain(vector<string>& w){
    int n=w.size();
    sort(begin(w),end(w),comp);
    vector<int>dp(n,1);
    int maxi=1;
    for(int i=0;i<n;i++){
      for(int prev=0;prev<i;prev++){
        if(checkPossible(w[i],w[prev]) && 1+dp[prev]>dp[i]){
          dp[i]=1+dp[prev];
        }
      }
      if(dp[i]>maxi) maxi=dp[i];
    }
    return maxi;
  }
};


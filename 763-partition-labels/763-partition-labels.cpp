class Solution {
public:
    vector<int> partitionLabels(string s) {
   int n=s.length();
   vector<int>res;
   vector<int>mpp(26,-1);
   //unordered_map<char,int>mpp;
   //storing last occurance of each char in hashmap
   for(int i=0;i<n;i++){
      mpp[s[i]-'a']=i;
   }
   int prev=-1,maxi=0;
   for(int i=0;i<n;i++){
    maxi=max(maxi,mpp[s[i]-'a']);
    if(maxi==i){
        res.push_back(maxi-prev);
        prev=maxi;
    }
   }
   return res;
  }
};
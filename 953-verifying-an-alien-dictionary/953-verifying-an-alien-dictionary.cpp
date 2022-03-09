class Solution {
  unordered_map<int,int>mpp;
  bool helper(string &a,string &b){
    int i=0;
    while(i<a.size() && i<b.size()){
      if(mpp[a[i]]!=mpp[b[i]]) return mpp[a[i]]<mpp[b[i]];
      i++;
    }
    return a.size()<=b.size();
  }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int size=order.size(),n=words.size();
        for(int i=0;i<size;i++) mpp[order[i]]=i;//mapping letter to its corresponding index
      //now check two words are lexicographically sorted
        for(int i=0;i<n-1;i++){
          if(!helper(words[i],words[i+1])) return false;
        }
      return true;
    }
};

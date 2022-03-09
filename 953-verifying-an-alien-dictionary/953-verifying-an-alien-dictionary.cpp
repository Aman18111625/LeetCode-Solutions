class Solution {
  unordered_map<int,int>mpp;
  bool helper(string &a,string &b){
    int i=0;
    while(i<size(a) && i<size(b)){
      if(mpp[a[i]]!=mpp[b[i]]) return mpp[a[i]]<mpp[b[i]];
      i++;
    }
    return size(a)<=size(b);
  }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<size(order);i++) mpp[order[i]]=i;//mapping letter to its corresponding index
      //now check two words are lexicographically sorted
        for(int i=0;i<size(words)-1;i++){
          if(!helper(words[i],words[i+1])) return false;
        }
      return true;
    }
};

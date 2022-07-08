class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
         vector<int>ans;
         int n=s.length(),m=p.length();
        if(m>n) return ans;//length of p is greater than length of given string then we can't any anagram 
       unordered_map<char,int>mpp;
      //store string p into mpp
      for(auto &ch : p) mpp[ch]++;
      int cnt=mpp.size();//number of different character
      int window=p.size();//size of window that we have to find 
      int start=0,end=0;
        while(end<n){
          //char are present in map
         if(mpp.find(s[end])!=mpp.end()){
           mpp[s[end]]--;//decrease it count in map
           if(mpp[s[end]]==0)  cnt--;
         }
        if(end-start+1<window)//length of substring from start to end is <k then continue
          end++;
        else if(end-start+1==window){
            if(cnt==0) ans.push_back(start);
            if(mpp.find(s[start])!=mpp.end()){
                    mpp[s[start]]++;
                    if(mpp[s[start]]==1)
                        cnt++;
                }
               start++;
               end++;
         }
      }
      return ans;
    }
};
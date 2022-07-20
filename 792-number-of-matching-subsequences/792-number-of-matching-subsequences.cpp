class Solution {
public:
   //to check whether str1 is sub-sequence of str2 or not
   bool isSubSequence(string str1,string str2){
      int j=0,n=str2.size(),m=str1.size();   
      for(int i=0;i<n && j<m;i++)
        if(str1[j]==str2[i]) j++;  
      
         return j==m;
     }
  
     int numMatchingSubseq(string s, vector<string>& words) {
        int count=0;
        map<string,bool>map;
        for(int i=0;i<words.size();i++){
         if(map.find(words[i])!=map.end()){
          if(map[words[i]]) count++;
         }
        else{
         bool match=isSubSequence(words[i],s);
         map[words[i]]=match;
         if(match) count++;
        }
      }
      return count;
    }
};
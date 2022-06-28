class Solution {
public:
  //TC:=>O(N)
  //SC:=>O(N)+O(N)=>O(2*N)=>O(N)
    int minDeletions(string s){
      //store count of each character in hashmap
        unordered_map<char,int>map;
        for(auto ch: s){
          map[ch]++;
        }
        unordered_set<int>st;//to take care of count of a character already present or not
        int ans=0;
        for(auto it : map){
          int freq=it.second;
          //if freq is alredy present in the set then reduce it untill it is not in set->reducing freq means removing that character
          while(st.count(freq)){
             freq--;
             ans++;
          }
          //add it 
          if(freq) st.insert(freq);
        }
        return ans;
    }
};
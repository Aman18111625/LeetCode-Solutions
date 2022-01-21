class Solution {
public:
    bool closeStrings(string word1, string word2) {
       if(word1.size()!=word2.size()) return false;
       map<char,int>mp1,mp2;
       for(auto &it: word1) mp1[it]++;
       for(auto &it: word2) mp2[it]++;
        vector<int>vec1,vec2;
       for(auto &it: mp1) vec1.push_back(it.second);
       for(auto &it: mp2) vec2.push_back(it.second);
       for(auto &it: mp1)
       {
         if(mp2.find(it.first)==mp2.end()) return false;
       }
       sort(vec1.begin(),vec1.end());
       sort(vec2.begin(),vec2.end());
      return vec1==vec2;
    }
};
 
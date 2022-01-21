class Solution {
public:
    int minSteps(string s, string t) {
        int freq1[26]={0};
        int freq2[26]={0};
        for(auto &it: s) freq1[it-'a']++;
        for(auto &it: t) freq2[it-'a']++;
        int len=0;
        for(int i=0;i<26;i++)
          len+=min(freq1[i],freq2[i]);
       return s.size()-len;
    }
};
class Solution {
public:
    vector<int> findFreq(string s){
      vector<int> freq(26,0);
      for(int i = 0; i < s.length(); i++)
            freq[s[i] - 'a']++;
        
      return freq;
    }
  
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
       //step-1 
        vector<int>maxFreq(26);
        for(auto word : words2){
           vector<int>freq = findFreq(word);
            for(int i = 0; i < 26; i++){
                maxFreq[i] = max(freq[i], maxFreq[i]);  // upadate freq to max freq
            }
        }
        
      vector<string>ans;
      for(auto word : words1){
         vector<int>freq=findFreq(word);
         bool flag=true;
         for(int i = 0; i < 26; i++){
            if(freq[i] < maxFreq[i]){
                  flag = false;
                  break;
              }
         }
         if(flag) ans.push_back(word);
      }
      return ans;
    }
};
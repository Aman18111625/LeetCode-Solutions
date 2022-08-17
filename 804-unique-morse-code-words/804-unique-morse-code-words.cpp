class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>arr={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string,int>map;
        for(auto word : words){
          string temp="";
          for(int i=0;i<word.size();i++){
             temp+=arr[word[i]-'a']; 
          }
          map[temp]=1;
        }
       return (int) map.size();
    }
};
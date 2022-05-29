class Solution {
public:
  //Brute-Force Approach->we're checking for every pairs of words according to the given condition
  //TC:->O(N^2)(nested for loop)
  //SC:->O(N)(using hashmap)
    // int maxProduct(vector<string>& words) {
    //   int ans=0;
    //   int n=words.size();
    //   for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //       unordered_map<int,int>mpp;
    //       bool flag=true;
    //       for(auto it : words[i]) mpp[it]++;
    //       for(auto it : words[j]){
    //         if(mpp.find(it)!=mpp.end()){
    //           flag=false;
    //           break;
    //         }
    //      }
    //      if(flag){
    //        ans=max(ans,((int)words[i].size())*((int)words[j].size()));
    //      }
    //    }
    //   }
    //   return ans;
    // }
  //Optimize Solution of Brute-Force
  // One way to efficiently check if two words have a letter in common is to just create an hashmap of size 26 and map each 26 letter of both the words as true/false depending upon whether it occurs in the word or not. Finally, we can iterate over this map and check if there's any letter that occurs in both the words and if it does, we know that the word have atleast 1 letter in common.Here, I have used bitset<26> instead of hashmap

   // Returns true if there's a common letter between bitset of two words
   bool checkCommon(bitset<26>& a, bitset<26>& b) {
    	for(int i = 0; i < 26; i++) 
        if (a[i] && b[i]) return true;
	    return false;
    }
  
     int maxProduct(vector<string>& words){
       int ans=0, n=words.size();
       vector<bitset<26>>chars(n);
       for(int i=0;i<n;i++){
         for(auto it : words[i]) chars[i][it-'a']=1;// map the letters to 1 if it occurs in the word
         //now check with all the other words .If there is no common letter then update ans
         for(int j=0;j<i;j++){
           if(!checkCommon(chars[i],chars[j])){
            ans=max(ans,(int)(words[i].size())*((int)words[j].size()));
            }
         }
       }
       return ans;
     }
};




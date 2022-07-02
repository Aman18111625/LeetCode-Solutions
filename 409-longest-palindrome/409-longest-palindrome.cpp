class Solution {
public:
/*
Intution:=>Using hashmap we can calculate frequency of each letters and
1)we know that for making Palindrome we need even pair of no
2) also we can take one odd no at the center
Example let's say 'aabbcc' is given so longest palindrom is 'abccba' all are occuring even no of times
Let's see another case 'abccccdd' here a=1, b=1, c=4, d=2 so here we can take all the letter occuring even no of time and 1 odd no occuring so ans would be 'dccaccd' or 'dccbccd'.
let's see one more example 'aaabbbb' here a=3 and b=4 times so we can take 'bbaaabb'
for this case we can take bool variable to take atmost 1 odd letter
*/
    int longestPalindrome(string s) {
       unordered_map<char,int>freq;
       for(auto &ch :s){
         freq[ch]++;
       }
       int ans=0;
       bool flag=false;
       for(auto &it : freq){
         int curr=it.second;
         if(curr%2==1){
           flag=true;
           ans+=(curr-1);
         }else{
           ans+=(curr);
         }
       }
       return flag?ans+1:ans;
    }
};


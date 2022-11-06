class Solution {
//Time Complexity:=> O((2^n)*k*(n/2)) O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length
// Space Complexity: O(k*x)
//to check whether given string is palindrome or not.
   bool isPalindrome(string& s,int start,int end){
      while(start<=end){
       if(s[start++]!=s[end--]) return false;
      }   
      return true;
    }
  
void helper(int ind,string s,vector<string>&path,vector<vector<string>>&res){
        int size=s.size();
        if(ind==size){
          res.push_back(path);
          return ;
        }  
        for(int i=ind;i<size;++i){
          //now we have to check for every index
         if(isPalindrome(s,ind,i)){
          path.push_back(s.substr(ind,i-ind+1));//substr from start=ind to end=i
          helper(i+1,s,path,res);
          path.pop_back();
         } 
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        int n=s.size();
        helper(0,s,path,ans);
       return ans;
    }
};
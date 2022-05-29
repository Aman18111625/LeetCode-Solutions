class Solution {
public:
  //Brute-Force Approach
  //TC:=>O(N^2)
  //SC:=>O(N)
    // int lengthOfLongestSubstring(string s) {
    //     if(s.empty())  return 0; 
    //     if(s==" ") return 1;
    //     int ans=0;
    //     int n=s.size();
    //     for(int i=0;i<n;i++){
    //       unordered_set<char>st;
    //       for(int j=i;j<n;j++){
    //         if(st.count(s[j])){
    //           ans=max(ans,j-i);
    //           break;
    //         }
    //         st.insert(s[j]);
    //       }
    //     }
    //     return ans;
    // }
     //Optimized Approach-1
    //TC:=>O(2*N)
   //SC:=>O(N)
  //Approach: We will have two pointers left and right. Pointer ‘left’ is used for maintaining the starting point of substring while ‘right’ will maintain the endpoint of the substring.’ right’ pointer will move forward and check for the duplicate occurrence of the current element if found then ‘left’ pointer will be shifted ahead so as to delete the duplicate elements.
   int lengthOfLongestSubstring(string str){
      int maxans = 0;
      int n=str.size();
      unordered_set < int > set;
      int l = 0;
     for (int r = 0; r < n; r++) {// outer loop for traversing the string
      if (set.find(str[r]) != set.end()) {//if duplicate element is found
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
     }
     set.insert(str[r]);
     maxans = max(maxans, r - l + 1);
   }
   return maxans;
  }
};
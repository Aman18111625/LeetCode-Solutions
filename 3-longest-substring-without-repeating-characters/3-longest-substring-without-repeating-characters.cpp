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
  //  int lengthOfLongestSubstring(string str){
  //     int maxans = 0;
  //     int n=str.size();
  //     unordered_set < int > set;
  //     int l = 0;
  //    for (int r = 0; r < n; r++) {// outer loop for traversing the string
  //     if (set.find(str[r]) != set.end()) {//if duplicate element is found
  //     while (l < r && set.find(str[r]) != set.end()) {
  //       set.erase(str[l]);
  //       l++;
  //     }
  //    }
  //    set.insert(str[r]);
  //    maxans = max(maxans, r - l + 1);
  //  }
  //  return maxans;
  // }
  
  //Optimized Approach-2
  //TC:=>O(N)
  //SC:=>O(1)
 // Approach: In this approach, we will make a map that will take care of counting the elements and maintaining the frequency of each and every element as a unity by taking the latest index of every element.
  int lengthOfLongestSubstring(string s) {
      vector < int > mpp(256, -1);
      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)//duplicate character
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;
        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};
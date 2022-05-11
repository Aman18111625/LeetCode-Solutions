class Solution {
public:
  //Approach-2 Without Using Extra Space
  //Time:=>O(N)
  //Space:=>O(1)
//     int countVowelStrings(int n) {
//        if(n==1) return 5;
//        int a=1, e=1, i=1, o=1, u=1;  
//         while(--n){
//             o += u;
//             i += o;
//             e += i;
//             a += e;
//         }
        
//         return a+e+i+o+u;
//     }
  //Approach-1 Using DP
  //Time:=>O(N)
  //Space:=>O(N)
   int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        int ans = 0;
        while(--n){
            for(int i=3; i>=0; i--){
                dp[i] += dp[i+1];
            }
        }
        for(auto x:dp) ans += x;
        return ans;
    }
};
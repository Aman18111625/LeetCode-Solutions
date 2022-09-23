class Solution {
public:
    const int mod=1e9+7;
  
    int numberOfBits(int n){
      return log2(n)+1;
    }
  
    int concatenatedBinary(int n) {
       long  ans=0;
       for(int i=1;i<=n;i++){
         int len=numberOfBits(i);
         ans=((ans<<len%mod)+i)%mod;
       }
      return ans;
    }
};
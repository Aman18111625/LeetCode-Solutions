class Solution {
public:
  /*Brute -Force 
  //TC:=>GOT TLE
    int countOdds(int low, int high) {
        int cnt=0;
        for(long long i=low;i<=high;i++)
           if(i&1) cnt++;
        return cnt;
    }*/
  int countOdds(int low, int high) {
        int cnt=(high-low)>>1;
        if((low&1) or  (high&1)) cnt++;
        return cnt;
    }
};
class Solution {
public:
  //Brute Force
  //Give TLE
  //Simply Run a loop from i=0 to i<n and everytime multiply x to our ans 
    // double myPow(double x, int n) {
    //     int  size=abs(n);
    //     double ans=1;
    //     for(int i=0;i<size;i++){
    //       ans*=x;
    //     }
    //     if(n<0) return (double)1/ans;
    //     return ans;
    // }
    double myPow(double x, int n){
     double ans = 1.0;
     long long nn = n;
     if (nn < 0) nn = -1 * nn;
      while (nn) {
        if (nn % 2) {
        ans = ans * x;
        nn = nn - 1;
       } else {
        x = x * x;
        nn = nn / 2;
      }
    }
    if (n < 0) ans = (double)(1.0) / (double)(ans);
    return ans;
    }
};
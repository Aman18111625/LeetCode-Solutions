class Solution {
public:
     //Brute-Force ->Using inbuilt sqrt() function
    //TC:=>(sqrt(num))
    //SC:=>O(1)
    // bool isPerfectSquare(int num) {
    //     int temp=sqrt(num);
    //     return temp*temp==num;
    // }
  //Optimal Approach->Using Binary Search
  //why Binary Search->As we have a search range so we can simply apply BS and check whether given num is perfect square or not.
  bool isPerfectSquare(int num) {
        if (num == 1) return true;
        long long lo = 1;
        long long hi = num / 2;
        
        while(lo <= hi) {
            long long mid = (lo + hi) / 2;
            long long sq = mid * mid;
            if (sq == (long long )num) return true;
            else if (sq < num) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return false;
    }
};
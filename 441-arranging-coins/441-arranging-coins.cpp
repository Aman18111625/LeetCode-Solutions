class Solution {
public:
    //Brute-Force Approach->Simple run a loop till n>=i and every time do n-=i && i++ 
    //TC:=>O(sqrt(N)) && SC:=>O(1)
    // int arrangeCoins(int n) {
    //     int i=1;
    //     while(n>=i){
    //       n-=i;
    //       i++;
    //     }
    //     return  i-1;
    // }
    //Optimal Approach->Using Binary Search
    //TC:=>o(logN) && SC:=>O(1)
    //we know that sum of  number from 1 to n = n*(n+1)/2;
    //here min sum can be =0 && maxi can be =n*(n+1)/2 -> this is our search space
    int arrangeCoins(int n){
        long low = 0, high = n, mid, tmp;
        while (low <= high) {
            mid = low + (high - low) / 2;
            tmp = mid * (mid + 1) / 2;
            if (tmp == n) return mid;
            if (tmp <= n) low = mid + 1;
            else high = mid - 1;
        }
        return low-1;
    }
};
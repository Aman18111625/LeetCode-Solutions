class Solution {
public:
  /*//Approach-1 Generate fibonacci series till k and then find minimum number
  Time-Complexity:=>O(N)
  Space-Complexity:=>O(N)
    int findMinFibonacciNumbers(int k) {
        vector<int>fib;
        fib.push_back(1);
        fib.push_back(1);
        for(int i=2;fib[i-1]+fib[i-2]<=k;i++){
          fib.push_back(fib[i-1]+fib[i-2]);
        }
        int ans=0;
        int size=fib.size();
       for(int i=size-1;i>=0;i--){
         if(k==0) break;
         if(fib[i]<=k){
           ans++;
           k-=fib[i];
         }
       }
      return ans;
    }*/
   int  findMinFibonacciNumbers(int n) {
    if (n <= 3) return n != 0;
    int s = 1, e = 1;
    while (e <= n) {
        int temp = s + e;
        s = e;
        e = temp;
    }
    return 1 + findMinFibonacciNumbers(n - s);
}

};
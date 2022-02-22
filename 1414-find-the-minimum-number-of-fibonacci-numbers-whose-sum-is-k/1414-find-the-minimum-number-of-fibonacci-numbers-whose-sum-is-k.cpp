class Solution {
public:
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
    }
};
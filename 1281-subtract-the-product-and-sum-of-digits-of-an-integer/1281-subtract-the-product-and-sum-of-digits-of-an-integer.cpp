class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0,prod=1;
        while(n){
          int rem=n%10;
          sum+=rem;
          prod*=rem;
          n/=10;
        }
      return (prod-sum);
    }
};
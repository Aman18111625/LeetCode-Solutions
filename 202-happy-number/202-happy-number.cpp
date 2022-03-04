class Solution {
    int helper(int& num)
    {
        int sum=0;
        while(num)
        {
            int t=num%10;
            sum+=(t*t);
            num/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        if(n==1) return true;
         while(1){
           if(n==1 or n==89) break;
           n=helper(n);
         }
        return n==1;
    }
};
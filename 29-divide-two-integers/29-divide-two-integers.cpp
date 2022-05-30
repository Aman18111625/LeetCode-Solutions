class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;//if both are equal
        //check output will come positive or negative
         bool pos=(dividend<0 == divisor<0);
         unsigned int a=abs(dividend),b=abs(divisor);
         unsigned int ans=0;
         while(a>=b){// while dividend is greater than or equal to divisor
           int quotient=0;
           while( a> (b<<(quotient+1))){
             quotient++;
           }
            ans+=(1<<quotient);// add the power of 2 found to the answer
            a-=(b<<quotient); // reduce the dividend by divisor * power of 2 found
         }
         if(ans == (1<<31) && pos) return INT_MAX;// if ans cannot be stored in int
         return pos==true?ans:-ans;
    }
};

// if(dividend == divisor)
//             return 1;
//         bool isPositive = (dividend<0 == divisor<0);    // if both are of same sign, answer is positive
//         unsigned int a = abs(dividend);
//         unsigned int b = abs(divisor);
//         unsigned int ans = 0;
//         while(a >= b){  // while dividend is greater than or equal to divisor
//             short q = 0;
//             while(a > (b<<(q+1)))
//                 q++;
//             ans += (1<<q);  // add the power of 2 found to the answer
//             a = a - (b<<q);  // reduce the dividend by divisor * power of 2 found
//         }
//         if(ans == (1<<31) and isPositive)   // if ans cannot be stored in signed int
//             return INT_MAX;
//         return isPositive ? ans : -ans;
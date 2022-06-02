class Solution {
public:
    int mySqrt(int x) {
     // return sqrt(x);
        if(x<2) return x;
        auto i=1;
        while(x/i>i)
        {
          i++;
        }
        return x/i;
    }
};
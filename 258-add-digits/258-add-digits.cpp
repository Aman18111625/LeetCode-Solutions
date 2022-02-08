class Solution {
  int getDigit(int n)
  {
    int cnt=0;
    while(n)
    {
      cnt++;
      n/=10;
    }
    return cnt;
  }
  
public:
    int addDigits(int num) {
       if(num==0 or getDigit(num)==1) return num;
        int sum=0;
        while(num)
        {
          sum+=(num%10);
          num/=10;
        }
      return addDigits(sum);
    }
};
class Solution {
public:
    string getSmallestString(int n, int k) {
        if(n==k) return string(n,'a');
        string arr=string(n,'a');
        //now traverse from at the end
        for(int i=n-1;i>=0;i--)
        {
          k-=i;
          if(k>=0)
          {
            if(k>=26)
            {
              arr[i]='z';
              k-=26;
            }else{
              char curr=(char)(k+97-1);
              arr[i]=curr;
              k-=(arr[i]+97);
            }
          }
          else break;
          k+=i;
        }
      return arr;
    }
};
class Solution {
public:
  /*
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
              k-=(arr[i]-'a'+1);
            }
          }
          else break;
          k+=i;
        }
      return arr;
    }*/
    string getSmallestString(int n, int k) {
        string res(n, 'a');
//since we want the lexicographically smallest string,therefore put n characters = a
// now the k should reduce by n since we placed n a's
         k-=n;
        int ptr = n-1;
        // ptr will point to end of string so that from the end we can start adding 
        // z's or whatever character is required
        // loop till k is > 0, because k is the sum which we have to achiveve. We'll go on reducing it.
        while (k) {
            // res[ptr] was 'a', now if we add 25 to 'a' it becomes 'z'
            // but let's say k initially was 27, and currently k = 5, means current sum = 22. so required sum = 5, so there's no point of adding 25. Therefore we take min of k and 25
            res[ptr--] += min(k, 25);
            k -= min(k, 25);
        }
        return res;
    }
};
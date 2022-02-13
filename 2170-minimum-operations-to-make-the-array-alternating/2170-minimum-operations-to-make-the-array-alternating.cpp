class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         int n=nums.size();
         if(n==1) return 0;
         int maxi=nums[0];
         int freqEven[100001]={0};
         int freqOdd[100001]={0};
         for(int i=0;i<n;i++)
         {
           if(i%2==0) freqEven[nums[i]]++;
           else freqOdd[nums[i]]++;
           maxi=max(maxi,nums[i]);
         }
        int firstMaxEven=0,freqFirstMaxEven=0,firstMaxOdd=0,freqFirstMaxOdd=0;
        int secondMaxEven=0,freqSecondMaxEven=0,secondMaxOdd=0,freqSecondMaxOdd=0;
        for(int i=1;i<=maxi;i++)
        {
          //for even
          if(freqEven[i]>=freqFirstMaxEven)
          {
            secondMaxEven=firstMaxEven;
            freqSecondMaxEven=freqFirstMaxEven;
            freqFirstMaxEven=freqEven[i];
            firstMaxEven=i;
          }else if(freqEven[i]>freqSecondMaxEven)
          {
            freqSecondMaxEven=freqEven[i];
            secondMaxEven=i;
          }
          //for odd
          if(freqOdd[i]>=freqFirstMaxOdd)
          {
             secondMaxOdd=firstMaxOdd;
            freqSecondMaxOdd=freqFirstMaxOdd;
            freqFirstMaxOdd=freqOdd[i];
            firstMaxOdd=i;
          }else if(freqOdd[i]>freqSecondMaxOdd)
          {
            freqSecondMaxOdd=freqOdd[i];
            secondMaxOdd=i;
          }
        }
      if(firstMaxEven!=firstMaxOdd) return n-freqFirstMaxEven-freqFirstMaxOdd;
      return min(n-freqFirstMaxEven-freqSecondMaxOdd,n-freqFirstMaxOdd-freqSecondMaxEven);
    } 
};
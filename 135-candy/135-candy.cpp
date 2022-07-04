class Solution {
public:
    //first simple assign each candidates to 1 candy
   // now iterate from i=1 to i<n & check if curr_ratings(ratings[i]) > prev_ratings(ratings[i-1]) then assign 1+prev_candy
  //now iterate from i=n-2 to i>=0 & check if curr_ratings(ratings[i])>next_ratings(ratings[i+1]+1) then assign max(curr_candy,1+next_candy)
  //TC:=>O(N)
  //SC:=>O(N)
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>candies(n,1);
        for(int i=1;i<n;i++)
         if(ratings[i]>ratings[i-1]) 
           candies[i]=candies[i-1]+1; 
        
        int sum=candies[n-1];
        for(int i=n-2;i>=0;i--){
         if(ratings[i]>ratings[i+1]) 
           candies[i]=max(candies[i],candies[i+1]+1);
         sum+=candies[i];
        }
        return sum;
    }
};
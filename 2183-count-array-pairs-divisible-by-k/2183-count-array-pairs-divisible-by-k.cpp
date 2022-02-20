class Solution {
public:
    long long countPairs(vector<int>&arr, int k) {
      unordered_map<int,int>mpp;//all left gcd are stored here
      long long ans=0;
      int n=arr.size();
      for(int i=0;i<n;i++){
        int gcd1=__gcd(arr[i],k);
        int gcd2=k/gcd1;
        //if nums[i] itselft divisible by k then it'll make pairs with every (n-1) elements
        if(gcd2==1){
          ans+=i;
        }//if am looking for missing gcd2,i can take any gcd which has gcd2 in it
        else{
          for(auto &it : mpp){
            if(it.first%gcd2==0) ans+=it.second;
          }
        }
        mpp[gcd1]++;
      }
      return ans;
    }
};
class Solution {
public:
  /*Brute Force
  Time-Complexity:=>O(N^2)
  Space-Complexity:=>O(1)
    int countPairs(vector<int>& d) {
      set<int>powerOfTwo;
      for(int i=0;i<=21;i++){
        powerOfTwo.insert(pow(2,i));
      }
      int mod=1e9+7,ans=0;;
      int n=d.size();
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
          int sum=d[i]+d[j];
          if(powerOfTwo.count(sum)) 
          {
            ans++;
          }
        }
      }
      return ans;
    }*/
  //Optimal Approach
  //Same As Two Sum 
   const int mod=1e9+7;
   int countPairs(vector<int>&d){
        int ans=0,n=d.size();
        unordered_map<int,int>mpp;
        mpp[d[0]]++;
        for(int i=1;i<n;i++){
            for(int p=1;p<=(1<<21);p*=2){
                if(mpp.find(p-d[i])!=mpp.end()){
                    ans=(ans+mpp[p-d[i]])%mod;
                }
            }
            mpp[d[i]]++;
        }
        return ans%mod;
    }
};
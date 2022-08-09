class Solution {
public:
    const int mod=1e9+7;
    unordered_map<int,int>dp;
  
    int helper(vector<int>&arr,unordered_map<int,int>&hash,int product){
      if(dp.find(product)!=dp.end()) return dp[product];
      int cnt=1;
      for(auto a: arr){
        //if both factor are available then increase cnt
        if((product%a==0) && hash[product/a]){
          cnt=(cnt+ (helper(arr,hash,a)%mod*1LL*helper(arr,hash,product/a)%mod)%mod)%mod;
        }
      }
      return dp[product] = cnt;
    }
   
    int numFactoredBinaryTrees(vector<int>& arr) {
        int ans=0;
        unordered_map<int,int>hash;
        for(auto a: arr) hash[a]++;
        for(auto a: arr){
          ans=(ans+helper(arr,hash,a)%mod)%mod;
        }
        return ans;
    }
};

      
  
/*
     const int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        vector < long long > dp(arr.size(), 1);
        unordered_map<int, int> mp;
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]] = i;//store the index of various elements of the array
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[i] % arr[j] == 0)//to check whether arr[j] is a factor of arr[i] or not
                {
                    int temp = arr[i] / arr[j];
                    if (mp.count(temp)) dp[i] += (dp[j] *dp[mp[temp]]) % mod;//check the presence of the required no in map, If it is in the map then increase dp[i] by the product of the dp[j] and dp[mp[temp]] taking the modulus
                }
            }
        }
        
        long long ans = 0;
        ans = accumulate(dp.begin(), dp.end(), 0LL);
        return ans%mod;//return toatl sum after taking modulus
    }
*/
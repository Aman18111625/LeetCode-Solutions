static bool cmp(pair<int,int>&a,pair<int,int>&b){
     if(a.second != b.second) return a.second < b.second;
     return a.first < b.first;
}

class Solution {
  int countSetBit(int n){
    if(n==0) return 0;
    int cnt=0;
    while(n)
    {
      n=n&(n-1);
      cnt++;
    }
    return cnt;
  }
  
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>ans;
        if(arr.size()==1) return arr;
        vector<pair<int,int>>hash;
        for(auto &it : arr)
        {
          int temp=countSetBit(it);
          hash.push_back({it,temp});
        }
        sort(hash.begin(),hash.end(),cmp);
        for(auto &it : hash) ans.push_back(it.first);
        return ans;
    }
};
class Solution {
  int countSetBit(int n){
    int cnt=0;
    while(n){
      if(n&1) cnt++;
      n>>=1;
    }
    return cnt;
  }
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
          ans.push_back(countSetBit(i));
        }
      return ans;
    }
};
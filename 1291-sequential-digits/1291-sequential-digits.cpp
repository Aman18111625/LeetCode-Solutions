class Solution {
  vector<int>ans;
  void dfs(int digit,int& low,int &high,int res)
  {
    long long num=(long long)res*10+digit;
    if(digit<=9 && num>=low && num<=high) 
    ans.push_back(num);
    if(num<high)
       dfs(digit+1,low,high,num);
  }
public:
    vector<int> sequentialDigits(int low, int high) {
        ans.clear();
      for(int i=1;i<=9;i++) dfs(i,low,high,0);
      sort(ans.begin(),ans.end());
      return ans;
    }
};
 
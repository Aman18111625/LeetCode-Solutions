class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& props) {
      sort(props.begin(),props.end());
      int ans=0,n=props.size();
      int a=props[n-1][0],b=props[n-1][1];
      int leftMax=props[n-1][1];
      for(int i=n-2;i>=0;i--){
        if(props[i][0]<props[i+1][0]) {
          b=max(leftMax,b);
          leftMax=max(b,props[i][1]);
        }
        if(props[i][0]<a && props[i][1]<b) ans++;
      }
      return ans;
    }
};
 
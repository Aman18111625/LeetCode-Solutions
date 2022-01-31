class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int maxi=0;
        int n=a.size(),m=a[0].size();
        for(int i=0;i<n;i++)
        {
          int temp=0;
          for(int j=0;j<m;j++)
          {
            temp+=a[i][j];
          }
          maxi=max(maxi,temp);
        }
      return maxi;
    }
};
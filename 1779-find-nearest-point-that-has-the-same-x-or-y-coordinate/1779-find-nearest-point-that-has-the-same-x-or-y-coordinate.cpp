class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>&p) {
        int ans=-1;
        int minDist=INT_MAX;
        int n=p.size();
       for(int i=0;i<n;i++){
         int X=p[i][0],Y=p[i][1];
         if(X==x or Y==y){
            int dist=abs(x-X)+abs(y-Y);
            if(minDist>dist){
               minDist=dist;
              ans=i;
            }
         }
       }
      return ans;
    }
};
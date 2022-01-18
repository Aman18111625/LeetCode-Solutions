class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
           int ans = 0;
        int m = f.size();
        for(int i=0;i<m;i++){
            bool f1 = true,f2 = true;
            if(f[i] == 0){
                if(i-1 >= 0){
                  if(f[i-1] != 0) f1 = false; 
               }
               if(i+1 < m){
                   if(f[i+1] != 0) f2 = false;
               }
               if(f1 && f2){
                   ans++;
                   f[i] = 1;
               } 
            }
        }
        return ans >= n ? true : false;
    }
};
  
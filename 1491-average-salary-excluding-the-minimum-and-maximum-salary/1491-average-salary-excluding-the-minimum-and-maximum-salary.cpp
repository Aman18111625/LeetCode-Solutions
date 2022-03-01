class Solution {
public:
    double average(vector<int>& s) {
        int mini=s[0],maxi=s[0];
         for(auto &it : s){
           mini=min(mini,it);
           maxi=max(maxi,it);
         }
        double ans=0;
        for(auto &it : s){
          if(it!=mini && it!=maxi) ans+=it;
        }
       return ans/(s.size()-2);
    }
};
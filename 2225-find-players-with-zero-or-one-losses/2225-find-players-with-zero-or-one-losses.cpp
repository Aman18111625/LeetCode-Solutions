class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
         int n=m.size();
         int maxi=0;
         unordered_map<int,int>win,lose;
         for(int i=0;i<n;i++){
           win[m[i][0]]++;
           lose[m[i][1]]++;
           maxi=max({maxi,m[i][0],m[i][1]});
         }
         vector<vector<int>>ans;
         vector<int>temp1,temp2;
         for(int i=1;i<=maxi;i++){
           if(win.find(i)!=win.end() && lose.find(i)==lose.end()){
             temp1.push_back(i);
           }
           else if(lose.find(i)!=lose.end() && lose[i]==1){
             temp2.push_back(i);
           }
         }
         ans.push_back(temp1);
         ans.push_back(temp2);
        return ans;
    }
};
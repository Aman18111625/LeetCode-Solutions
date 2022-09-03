class Solution {
public:
    int digits(int x){
       int cnt=0;
       while(x){
         cnt++;
         x/=10;
       }
       return cnt;
    }  
  
    void findNumbers(int curr,int n,int k,vector<int>&res){
       if(digits(curr)==n) {
         res.push_back(curr);
         return ;
       }
       for(int i=0;i<10;i++){
          int last=curr%10;
          if(abs(last-i)==k){
            findNumbers((curr*10+i),n,k,res);
          } 
       }
    }
  
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i=1;i<10;i++){
          findNumbers(i,n,k,ans);
        }
        return ans;
    }
};

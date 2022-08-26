class Solution {
public:
   string sortedNum(int n){
     string res=to_string(n);
     sort(res.begin(),res.end());
     return res;
   }
  
    bool reorderedPowerOf2(int n) {
        string ans=sortedNum(n);
        for(int i=0;i<32;i++){
          if(ans==sortedNum(1<<i)) return true;
        }
        return false;
    }
  
};
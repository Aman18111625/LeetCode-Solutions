class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num==0) return true;
        if(num==1) return false;
        for(int i=num>>1;i<=num;i++){
          string temp=to_string(i);
          reverse(temp.begin(),temp.end());
          int n=stoi(temp);
          if((i+n)==num) return true;
        }
        return false;
    }
};
 
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
      int n=s.size();
      int i=0,ans=0;
      int Count=count(s.begin(),s.end(),'1');
      while(Count){
        if(s[i]=='1') {//so there's no chance of "01"
          Count--;
          i++;
        }else{
          //now there's a chance of "01" so now check "01" and replace them with "10"
          for(int j=i;j<n-1;j++){
             if(s[j]=='0' && s[j+1]=='1'){
                s[j]='1';
                s[j+1]='0';
                j++;
             }
          }
          ans++;
        } 
      }
      return ans;
    }
};


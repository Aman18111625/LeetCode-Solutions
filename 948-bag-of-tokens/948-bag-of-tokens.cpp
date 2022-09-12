class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
      int n=tokens.size();
      int ans=0;
      int i=0,j=n-1;
      sort(tokens.begin(),tokens.end());
      while(i<j){
        if(power>=tokens[i]){
          power-=tokens[i];
          i++;
          ans++;
        }else if(ans>=1 && power+tokens[j]>=tokens[i]){
          power+=tokens[j];
          j--;
          ans--;
        }else break;
      }
      while(i<j+1 && power>=tokens[i]){
        power-=tokens[i];
        i++;
        ans++;
      }
      return ans;
    }
};


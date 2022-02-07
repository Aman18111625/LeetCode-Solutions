class Solution {
public:
    int numSplits(string s) {
         int cnt=0;
         map<char,int>left,right;
         for(auto &it : s) 
            right[it]++;
         for(auto &it : s)
         {
           left[it]++;
           right[it]--;
           if(right[it]==0) right.erase(it);
           if(left.size()==right.size()) cnt++;
         }
      return cnt;
    }
};
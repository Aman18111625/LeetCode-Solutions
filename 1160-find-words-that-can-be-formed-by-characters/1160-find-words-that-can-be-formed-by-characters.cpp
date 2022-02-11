class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
      /*  
      map<char,int>mpp1,mpp2;
        for(auto &it : chars) mpp1[it]++;
        int ans=0;
        for(auto &str: words)
        {
          mpp2=mpp1;
          int cnt=0;
          for(auto &ch: str)
          {
               if(mpp2.find(ch)!=mpp2.end() && mpp2[ch]>0)
               {
                 mpp2[ch]--;
                 cnt++;
               }
          }
          mpp2.clear();
          if(cnt==str.size()) ans+=str.size();
        }
      return ans;*/
    unordered_map<char,int>mpp;
    for(auto &it : chars) mpp[it]++;
    int ans=0;
    for(auto &str: words)
    {
        unordered_map<char,int>mpp2;
        bool flag=true;
        for(auto &it: str)
        {
            mpp2[it]++;
        }
        for(auto &it : str)
        {
          if(mpp2[it]>mpp[it])
          {
              flag=false;break;
          }
        }
        if(flag) ans+=str.size();
    }
    return ans;
    }
};
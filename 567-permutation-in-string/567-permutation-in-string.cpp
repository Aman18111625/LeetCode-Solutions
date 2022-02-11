class Solution {
public:
  /*
  //Approach-1 Using Hashmap
  //TC:=>O(N) 
  //SC:=>O(N)
    bool checkInclusion(string s1, string s2) {
      unordered_map<char,int>mpp;
      for(auto &ch : s1) mpp[ch]++;
      int win=s1.size();//size of window
      int cnt=mpp.size();//no of distinct char in s1
      int i=0,j=0,n=s2.size();
      while(j<n)
      {
          if(mpp.find(s2[j])!=mpp.end())
          {
            mpp[s2[j]]--;
            if(mpp[s2[j]]==0) cnt--;
          }
          if(j-i+1<win)j++;
          else if(j-i+1==win)
          {
             if(cnt==0) return true;
             if(mpp.find(s2[i])!=mpp.end())
             {
               mpp[s2[i]]++;
               if(mpp[s2[i]]==1) cnt++;
             }
            i++;j++;
          }
       }
      return false;
    }*/
  //Appproach-2 Using Freq Array
  //TC:=>O(N)(length of s2)
  //SC:=>O(26)+O(26)=>O(1)
  bool checkInclusion(string s1, string s2){
        string mpp1(26,0), mpp2(26,0);
        for( auto &ch : s1) mpp1[ch-'a']++; 
        int n=s2.size(),win=s1.size();
        for( int i = 0 ; i < n; i++){
            mpp2[s2[i]-'a']++;
            if( i >= win ) mpp2[s2[i-win] - 'a']--;
            if( mpp1 == mpp2) return true;
        }  
    return false;
  }
};

  
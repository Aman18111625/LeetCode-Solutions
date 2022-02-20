class Solution {
public:
  /*
  //Using hashmap and Priority_queue 
  //Time-Complexity:=>O(N)(traversing string) 
  //Space-Complexity:=>O(N)+O(N)
  //We can optimize space because we know here only we have to use lowercase character
    string repeatLimitedString(string s, int Limit) {
            //unordered_map<char,int>mpp;//to store freq of each character
            int mpp[26]={0};
            for(auto &ch: s) mpp[ch-'a']++;
            priority_queue<pair<char,int>>pq;//max-heap->we have to given lexicohraphically largest  string;
      // push all the char with their freq into max-heap
            for(int i=0;i<26;i++)
            {
              if(mpp[i]) pq.push({i+'a',mpp[i]});
            }
            string res="";
            while(!pq.empty()){
                auto top=pq.top(); pq.pop();//take top element of max-heap
                char ch=top.first;
                int freq=top.second;
                int mini=min(Limit,freq);//take min freq
                while(mini--) res+=ch;//include in ans string
                if(pq.empty()) return res;
                freq-=min(Limit,top.second);//decrease freq
                if(freq){//if still freq >0 then we have to add second top most char here
                  auto sc=pq.top(); pq.pop();
                  char chh=sc.first;
                  int fq=sc.second;
                  res+=chh; 
                  fq--;
                  if(fq) pq.push({chh,fq});
                  pq.push({ch,freq});
                }
            }
           return res;
    }*/
  //Using Stack
   string repeatLimitedString(string s, int k) {
        string ans="";
        int arr[26]={0};//to store freq
        for(auto &ch:s)
            arr[ch-'a']++;
        
        stack<pair<int,int>>st;
        for(int i=0;i<26;i++)
            if(arr[i]) st.push({i,arr[i]});
        
        while(!st.empty())
        {
            auto temp=st.top(); st.pop();
            int ch=temp.first;
            int freq=temp.second;
            int t=min(k,freq);
            while(t--)
                ans+=('a'+ch);
            if(freq-k>0)
            {
                if(st.empty())
                    break;
                else
                {
                    auto p=st.top(); st.pop();
                    if(p.second-1>0)
                        st.push({p.first,p.second-1});
                    st.push({ch,freq-k});
                    st.push({p.first,1});
                }
            }
        }
        
        return ans;
    }
};

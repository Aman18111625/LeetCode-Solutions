class Solution {
public:
    string repeatLimitedString(string s, int Limit) {
            unordered_map<char,int>mpp;//to store freq of each character
            for(auto &ch: s) mpp[ch]++;
            priority_queue<pair<char,int>>pq;//max-heap->we have to given lexicohraphically largest  string;
      // push all the char with their freq into max-heap
            for(auto &it : mpp) pq.push({it.first,it.second});
            string res="";
            while(!pq.empty()){
                auto top=pq.top(); pq.pop();//take top element of max-heap
                char ch=top.first;
                int freq=top.second;
                int mini=min(Limit,top.second);//take min freq
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
    }
};
  /*
    vector<int> hash(26);
        for(int i=0;i<s.length();i++) hash[s[i]-'a']++;
        priority_queue<pair<char,int>> pq; 
        for(int i=0;i<26;i++) if(hash[i]) pq.push({'a'+i,hash[i]});
        string res="";
        while(!pq.empty()){
            char c=pq.top().first; int freq=pq.top().second; pq.pop();
            int temp=min(limit,freq);
            while(temp--) res.push_back(c);
            if(pq.empty()) return res;
            freq=freq-min(limit,freq);
            if(freq){
                char smol=pq.top().first; int smolfreq=pq.top().second; pq.pop();
            res.push_back(smol); smolfreq--;
            if(smolfreq) pq.push({smol,smolfreq});
                pq.push({c,freq});
            }
            
        }
        return res;
    */
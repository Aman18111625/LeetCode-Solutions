class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        if(n==1) return s;
         unordered_map<char,int>mpp;
        for(auto ch : s) mpp[ch]++;
        priority_queue<pair<int,char>>pq;
        for(auto it : mpp)
            pq.push({it.second,it.first});
        
         string res;
         while(!pq.empty()){ 
             auto curr=pq.top();
             pq.pop();
              while(curr.first){
                  res.push_back(curr.second);
                  curr.first--;
              }
         }
        return res; 
    }
};
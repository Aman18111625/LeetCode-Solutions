class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        unordered_map<char,int>mpp;
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<n;i++) mpp[s[i]]++;
        
        for(auto it : mpp)
            pq.push({it.second,it.first});
        
        string res;
        while(pq.size()>1){
            auto p1=pq.top();
            pq.pop();
            auto p2=pq.top();
            pq.pop();
            
            res+=p1.second;
            res+=p2.second;
            
            p1.first--;
            p2.first--;
            
            if(p1.first) pq.push(p1);
            if(p2.first) pq.push(p2);
        }
        
        if(!pq.empty()){
            if(pq.top().first>1) return "";
            else res+=pq.top().second;
        }
        return res;
    }
};
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        vector<pair<int,int>>v(n);//store in pairs as {start time,end time}
        int i=0;
        for(auto &it : events)
        {
           v[i]={it[0],it[1]};
           i++;
        }
      sort(v.begin(),v.end());//sort according to the start time
      priority_queue<int,vector<int>,greater<int>>pq;
        i=0;
      int res=0,day=0;
      while(!pq.empty() or i<n)
      {
        if(pq.empty()) day=v[i].first;
        while(i<n && v[i].first<=day) 
            pq.push(v[i++].second);
        pq.pop();
        ++res,++day;
        while(!pq.empty() && pq.top()<day) pq.pop();
      }
      return res;
    }
};
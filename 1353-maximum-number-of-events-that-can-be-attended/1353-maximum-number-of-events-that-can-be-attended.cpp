class Solution {
public:
  /*
  Thought Process:=>
  First of all we'll sort all the events according to start time ,Now we're           basically adding all the activites that start on a same given day.
  Out of these we now attend the one which ends at the earliest possible.
  We increment the day and hence remove all the activites which coudn't be attended.

  */
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
      priority_queue<int,vector<int>,greater<int>>pq;//min-Heap
        i=0;
      int res=0,day=0;
      while(!pq.empty() or i<n)
      {
        if(pq.empty()) day=v[i].first;
        while(i<n && v[i].first<=day) //now push end time of all the pairs which have start time<=day 
            pq.push(v[i++].second);
        //attending all the activity which have earlist ending
        pq.pop();
        ++res,++day;
        //Removing all the activites which now coudn't be attended
        while(!pq.empty() && pq.top()<day) pq.pop();
      }
      return res;
    }
};
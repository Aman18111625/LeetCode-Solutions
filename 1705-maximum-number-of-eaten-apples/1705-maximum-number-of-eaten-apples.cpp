class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
       int  n=apples.size();
       int day=0;//curr day
       int ans=0;//store maximum number of apples 
       unordered_map<int,int>map;//store apples with deadline
      //minHeap->so that we can chhose first those are going rotten earlier.
       priority_queue<int,vector<int>,greater<int>>minHeap;
       while(day<n || !minHeap.empty()){
           if(day<n && days[day]!=0 && apples[day]!=0 ) {
              map[day+days[day]]+=apples[day];
              minHeap.push(day+days[day]);
           }
          //remove rotten apples or zero apples deadlines
           while(!minHeap.empty() && (minHeap.top()<=day || map[minHeap.top()]<=0)){
             minHeap.pop();
           }
           //consume at most one apple a day
           if(!minHeap.empty()){
              ans++;
              map[minHeap.top()]--;
           }
           day++;
       }
       return ans;
    }
};

      
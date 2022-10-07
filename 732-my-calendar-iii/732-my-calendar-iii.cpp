class MyCalendarThree {
    map<int,int>map;
public:
    MyCalendarThree() {
        map.clear();
    }
    
    int book(int start, int end) {
      map[start]++;
      map[end]--;
      int ans=0,event_on=0;
      for(auto it: map){
        ans=max(ans,event_on+=it.second);
      }
      return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */